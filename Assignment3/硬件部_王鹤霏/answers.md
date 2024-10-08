# 后端

## 后端与oop的相似之处

oop中应用程序使用MVC架构，后端对应其中的M和C。其中M是模型，C是控制器，即后端中的功能。在M-V-C之间，信息相互隔离，信息交换遵循一定的协议/接口。

## django和flask的异同点

同：都是基于Python的web框架内，采用MVC架构模式，并是开源项目。
异：

| | flask | django |
| --- | --- | --- |
| 规模 | 轻量级，核心部分很小，提供了基础的路由、请求处理等功能，其他功能则通过扩展来添加 | 全栈式的框架，包含了数据库管理、用户认证、URL 路由、模板引擎等许多内置功能 |
| 数据库支持 | 没有用于数据库处理的内置抽象层，也没有形成验证支持，但支持利用扩展添加这些功能 | 自带了一个 ORM（对象关系映射），可以方便地进行数据库操作，并且支持多种数据库后端 |
| 模板语言 | 默认使用 Jinja2 模板引擎 | 使用自己的模板语言 Django Templates |
| 使用场景 | 小型项目或需要高度定制化的应用 | 大型、复杂的应用程序，尤其是那些需要快速开发并且具有高度安全性的应用 |

## 节日信息共享系统后端设计方案

### 模型

节日：
- id；
- 名称；
- 时间（日期，或时间规则，如“三月第一个星期天”）；
- （上传者）；
- 补充信息，如习俗，地域，等。

### 功能

+ 上传节日
    - 前端：
        * 获取用户输入的节日信息；
        * 检查信息形式合法（无非法字符，日期不超限等）；
    - 后端：
        * 获取节日信息；
        * 检验信息内容合法（如日期规则合理，与已有节日不重复）；
        * 将信息存入数据库；
+ 显示节日
    - 前端：
        * 获得后端提供的有序排列的节日信息；
        * 展示；
    - 后端：
        * 调取数据库中的节日信息并有序排列后返回给前端；
+ 修改节日：
    - 前端：
        * 选中节日；
        * 获得后端提供的有序排列的节日信息并展示；
        * 获取用户输入的新的节日信息；
        * 检查信息形式合法（无非法字符，日期不超限等）；
    - 后端：
        * 获取节日id，从数据库中调取相应信息返回给前端；
        * 检验信息内容合法（如日期规则合理，与已有节日不重复，不冲突）；
        * 将新的信息存入数据库；

## django项目实现

见festivals.py


