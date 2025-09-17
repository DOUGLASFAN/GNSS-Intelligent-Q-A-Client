# GNSS 智能问答客户端

这是一个基于Qt开发的GNSS（全球导航卫星系统）智能问答客户端应用程序，允许用户与本地部署的AI服务进行交互，获取关于GNSS相关问题的解答。

## 项目概述

该应用程序提供了一个简洁的用户界面，用户可以输入关于GNSS的问题，系统将问题发送到本地运行的AI服务，并以流式方式显示回答结果。应用程序支持对话历史记录，使交互更加自然连贯。

## 技术栈

- C++
- Qt 6 框架
  - Qt Core
  - Qt GUI
  - Qt Widgets
  - Qt Network

## 项目结构

```
├── main.cpp                # 应用程序入口点
├── mainwindow.h/.cpp       # 主窗口类定义和实现
├── networkclient.h/.cpp    # 网络客户端类定义和实现
├── mainwindow.ui           # UI设计文件
├── nmeaCharAI.pro          # Qt项目文件
└── README.md               # 项目说明文档
```

## 核心功能

1. **用户界面**：简洁的问答界面，包括问题输入框、提问按钮和回答显示区域
2. **网络通信**：与本地8000端口的AI服务进行HTTP通信
3. **流式显示**：回答内容以打字机效果流式显示，提升用户体验
4. **对话历史**：保存对话上下文，支持连续问答

## 构建和运行

### 前提条件

- 已安装Qt 6开发环境
- 已安装MSVC 2022编译器（或其他兼容的C++编译器）
- 本地已部署并运行了AI服务（监听127.0.0.1:8000端口）

### 使用Qt Creator构建

1. 打开Qt Creator
2. 选择"文件" -> "打开文件或项目"
3. 选择项目目录下的`nmeaCharAI.pro`文件
4. 选择构建套件（建议使用Desktop Qt 6.x.x MSVC 64bit）
5. 点击"构建" -> "构建项目'nmeaCharAI'"
6. 构建成功后，点击"运行"按钮启动应用程序

### 命令行构建

```bash
# 在项目目录下执行
qmake
make (或 mingw32-make、nmake，取决于编译器)
```

## 使用说明

1. 确保本地AI服务已启动并监听8000端口
2. 启动GNSS智能问答客户端应用程序
3. 在问题输入框中输入您的问题
4. 点击"提问"按钮发送问题
5. 等待AI回答，回答内容将以流式方式显示在回答区域
6. 您可以继续提问，应用程序会保留对话历史

## 网络请求格式

客户端向服务器发送的请求格式：

```json
{
  "conversation": [
    {"role": "user", "content": "问题内容"},
    {"role": "assistant", "content": "历史回答"}
    // ...更多对话历史
  ]
}
```

服务器返回的响应格式：

```json
{
  "answer": "AI的回答内容"
}
```

## 注意事项

- 确保本地AI服务正确运行在127.0.0.1:8000端口
- 如果网络请求失败，应用程序会显示错误信息
- 程序支持基本的中文显示，但确保您的Qt环境配置了正确的字体


# GNSS Intelligent Q&A Client

This is a GNSS (Global Navigation Satellite System) intelligent question and answer client application developed based on Qt. It allows users to interact with a locally deployed AI service to get answers to GNSS-related questions.

## Project Overview

The application provides a clean user interface where users can input questions about GNSS. The system sends the questions to the locally running AI service and displays the answer results in a streaming manner. The application supportsapplication supports conversation history to make interactions more natural and coherent.

## Technology Stack

- C++
- Qt 6 Framework
  - Qt Core
  - Qt GUI
  - Qt Widgets
  - Qt Network

## Project Structure

```
├── main.cpp                # Application entry point
├── mainwindow.h/.cpp       # Main window class definition and implementation
├── networkclient.h/.cpp    # Network client class definition and implementation
├── mainwindow.ui           # UI design file
├── nmeaCharAI.pro          # Qt project file
└── README.md               # Project documentation
```

## Core Features

1. **User Interface**: Clean Q&A interface including question input box, question button, and answer display area
2. **Network Communication**: HTTP communication with AI service on local port 8000
3. **Streaming Display**: Answer content displayed with typewriter effect to enhance user experience
4. **Conversation History History**: Saves conversation context to support continuous Q&A

## Building and Running

### Prerequisites

- Qt 6 development environment installed
- MSVC 2022 compiler (or other compatible C++ compiler) installed
- Locally deployed and running AI service (listening on 127.0.0.1:8000)

### Building with Qt Creator

1. Open Qt Creator
2. Select "File" -> "Open File or Project"
3. Choose the `nmeaCharAI.pro` file in the project directory
4. Select a build kit (recommended: Desktop Qt 6.x.x MSVC 64bit)
5. Click "Build" -> "Build Project 'nmeaCharAI'"
6. After successful build, click the "Run" button to launch the application

### Command Line Build

```bash
# Execute in the project directory
qmake
make (or mingw32-make, nmake, depending on your compiler)
```

## Usage Instructions

1. Ensure the local AI service is started and listening on port 8000
2. Launch the GNSS Intelligent Q&A Client application
3. Enter your question in the question input box
4. Click the "Ask" button to send the question
5. Wait for the AI answer, which will be displayed in a streaming manner in the answer area
6. You can continue asking questions as the application retains conversation history

## Network Request Format

Request format sent by client to server:

```json
{
  "conversation": [
    {"role": "user", "content": "Question content"},
    {"role": "assistant", "content": "Historical answer"}
    // ...more conversation history
  ]
}
```

Response format returned by server:

```json
{
  "answer": "AI's answer content"
}
```

## Notes

- Ensure the local AI service is running correctly on 127.0.0.1:8000
- If network requests fail, the application will display error messages
- The program supports basic Chinese display, but ensure your Qt environment is configured with appropriate fonts
