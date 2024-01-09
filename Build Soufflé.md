# Build Soufflé

参考：https://souffle-lang.github.io/build

在https://github.com/souffle-lang/souffle/releases/tag/2.4.1 下载Source Code。

需要flex与bison库，可以通过Chocolatey进行安装。

https://chocolatey.org/install#individual 安装Chocolatey。

运行命令：

```
choco install winflexbison3
```

进入Souffle目录，运行命令（此处install-dir不知有何用处，后面将缺失且可选的package全设置了OFF）：

```
cmake -S . -B build -DCMAKE_INSTALL_PREFIX=<install-dir>  -DSOUFFLE_USE_CURSES=OFF -DSOUFFLE_USE_ZLIB=OFF -DSOUFFLE_USE_SQLITE=OFF -DSOUFFLE_USE_LIBFFI=OFF
```

运行成功后在souffle-2.4.1\build下，使用Visual Studio打开souffle.sln。

在生成过程中会出现一些错误，一般可通过以下方法解决：

1. 将解决方案资源管理器中的项目属性-配置属性-常规-C++语言标准改为C++17；
2. 属性-配置属性-C/C++-C将警告视为错误改为否；
3. 如果报preprocessor错误，在MainDriver.cpp中871行直接改为: `const bool use_preprocessor = false;`
4. 在libsouffle的项目属性-配置属性-C/C++-命令行中添加`/utf-8`；
5. 如果还有报字符编码相关错误，选择报错文件，点击文件-另存为，在”保存“按钮右侧的下拉框中选择”编码保存“，编码设置为Unicode(UTF-8 带签名)，保存到原位置，覆盖原文件。

build成功后，souffle-2.4.1\build\src中应该会有souffle.exe。可将文件目录添加到系统变量Path中。

### 运行简单示例

参考：https://souffle-lang.github.io/simple

### 使用C++ interface

参考：https://souffle-lang.github.io/interface

运行命令：

````
souffle -g <name>.cpp program.dl
````

生成规则集program.dl对应的cpp文件。

在Visual Studio中新建C++控制台项目，将以上cpp文件导入。在该cpp文件第一行添加：

```cpp
#define __EMBEDDED_SOUFFLE__
```

项目属性-配置属性-常规-C++语言标准改为C++17。

在该项目属性-配置属性-VC++目录-外部包含目录中，添加souffle-2.4.1\src\include对应目录。

将main改为类似以下：

```cpp
#include <souffle/SouffleInterface.h>

int main() {
    // testlib为上面对应的<name>
    if (souffle::SouffleProgram* prog = souffle::ProgramFactory::newInstance("testlib")) {
        // load facts目录下的csv文件
        prog->loadAll("facts");
        prog->run();
        prog->printAll();

        delete prog;
    }
    else {
        std::cerr << "Failed to create instance\n";
        return 1;
    }
    return 0;
}
```

运行成功后，目录下应该有输出的csv文件。
