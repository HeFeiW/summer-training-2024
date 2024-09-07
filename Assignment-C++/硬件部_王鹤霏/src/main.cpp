#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <curl/curl.h>

using json = nlohmann::json;
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp){
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}
int main(int argc, char** argv) {
    std::cout << "hello world!" << std::endl;
    std::ifstream file("./config.json");
    if (!file.is_open()) {
        std::cerr << "Failed to open config.json" << std::endl;
        return 1;
    }
    json config;
    file >> config;
    std::string url = config["url"];
    if (url.empty()) {
        std::cerr << "URL not found in config.json\n";
    }

    curl_global_init(CURL_GLOBAL_ALL);
    CURL* curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        std::string response;
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } 
        else {
            // 保存页面内容到文件
            std::ofstream outfile("webpage.html");
            if (!outfile.is_open()) {
                std::cerr << "Failed to create webpage.html" << std::endl;
                return 1;
            }
            outfile << response;
            outfile.close();
            std::cout << "Successfully downloaded webpage from json!";
        }

        // 清理curl会话
        curl_easy_cleanup(curl);
    }

    // 清理libcurl
    curl_global_cleanup();
    return 0;
}
