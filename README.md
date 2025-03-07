适用于SZU电子信息工程学院嵌入式信息处理与DSP实现

## 初始化
- 安装vscode stm32extension
- 安装STM32Cube MX、IDE、CLT、FINDER、Programer
- 在extension设置中天机路径

## 添加新工程
- 打开Cube MX配置完成、以Cmake工程生成
- 在vscode中打开文件夹

## 添加Cube MX工程
- 将Cume MX工程用MX打开
- 设置为Cmake后生成代码
- 打开文件夹

## LSP
若要生成compiele_commands.json文件，需要在CmakeLists.txt中添加
```cmake
# Set Compile_command
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
```
Compile_commands.json默认生成在build中，在根目录下创建.clangd文件指定路径
```
{
CompileFlags:
    CompilationDatabase: build\Debug
}
```