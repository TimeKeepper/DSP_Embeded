适用于SZU电子信息工程学院嵌入式信息处理与DSP实现

## 初始化
- 安装vscode stm32extension
- 安装STM32Cube MX、IDE、CLT、FINDER、Programer
- 在extension设置中添加路径

## 添加新工程
- 打开Cube MX配置完成、以Cmake工程生成
- 在vscode中打开文件夹

## 添加Cube MX工程
- 将Cume MX工程用MX打开
- 设置为Cmake后生成代码
- 打开文件夹

## 添加Pio工程
- 安装pio插件
- 不要使用GUI安装platform，嗨慢
- 到官网<https://github.com/platformio/platform-ststm32>
- 下载zip文件，使用pio cli命令
```bash
pio platform install file://path/to/zip
```
- 等待他安装完platform后会安装编译器和std lib（1G左右，非常慢，但你至少能看到进度条了）

## LSP
若要生成compiele_commands.json文件，需要在CmakeLists.txt中添加
```cmake
# Set Compile_command
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
```
Compile_commands.json默认生成在build中，在根目录下创建.clangd文件指定路径
```
CompileFlags:
    CompilationDatabase: build\Debug
```
对于pio来说，需要在pio cli下运行
```bash
pio run -t compiledb
```
还没完，pio默认不会包含工具链的头文件，这导致clangd不能完整进行代码提示，std使用困难，似乎每个人都觉得这很蠢，除了pio维护者，因此一个23年就提出的issue，24年就提出的pr至今依旧无人问津，我们根据这个pr<https://github.com/platformio/platformio-core/pull/4937>进行修改，现在你只需要将本工程中的platformio文件覆盖复制到你的`${USERPROFILE}/.platformio/penv/Lib/site-packages/`下就可以了