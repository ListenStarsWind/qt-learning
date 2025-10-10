# QT

## 引子

我们将要学习QT, 但QT到底是用来干什么的呢? 这个引子将解决这个问题.

首先, 既然我们已经学到QT了, 那应该就对互联网的核心岗位有了一定的理解:

- 开发
  对于开发来说, 简单的说, 就是程序员, 也是我们之后主要考虑的岗位
- 测试
  程序没问题才能交付给客户, 测试就是尽可能确保程序没有问题的一个岗位
- 运维
  运维主要在大厂, 他们一般负责管理服务器
- 产品经理
  产品经理其实是一个非技术岗, 他的主要职责是向开发人员描述需求, 由于他对技术可能不是很了解, 所以可能向开发人员提出一个较为离谱的需求, 因此经常与开发人员产生摩擦.

那我们QT在哪里呢? 我们QT是在开发里的, 对于开发来说, 又可以具体分为

1. 后端开发
2. 前端开发
3. 算法工程师
4. 游戏开发
5. ...

而在前端开发里, 有可以分为 1) 网页开发, 2) 桌面应用开发 3)移动程序开发, 我们的QT就在桌面开发里面, 说白了就是做电脑里的客户端. 对于客户端开发, 是前段开发的一个经典分支, 从苹果把第一个图形化界面系统退出后就正式登场了, 也就是上世纪八十年代的时候,  其它两个都是后来有的, 另外, 前端开发根据不同语境可能特指不同的分支或者大前端, 要注意区分.  

----

在上面的讨论中, 我们提到了"客户端"这个概念, "客户端"就是直接和用户打交道的这一端程序, 与之对应的就是"服务端", 有时, 仅依靠"客户端"不足以满足用户的需求, 这时候就需要"服务端"将各个客户端联系起来, 比如, 对于打车, 用户输入目的地, 生成订单, 订单发送到服务端, 服务端进行解析订单分配, 从而让用户打到车, 当然有的客户端也不用网, 或者网络属性不强, 比如Windows的画图板, 这分Markdown文档的编辑器Typora, 它们也是客户端, 所以说, 对于客户端来说, 其含义还是比较灵活的.

根据平台的不同, 客户端就有电脑桌面和移动设备的区别, QT主攻的就是电脑桌面级别的客户端开发, 尽管QT也支持进行移动开发, 但是并不是市场上的主流移动开发方案, 毕竟有现成的方案, 我为什么要改呢?

对于客户端来说, 一个很重要的任务, 就是编写和用户交互的界面, 界面有两种分隔 1) TUI, 即"Text User Interface"(文本用户界面), 就是敲命令行的, 2) GUI, 即"Graphical User Interface"(图形化用户界面).   对于TUI, 来说, 一般面向的是从事开发岗位的专业软件, 而GUI, 就是面向普通用户. QT就是编写桌面GUI程序的框架. 不过对于Windows, 也有其他的GUI程序开发方案.

TUI和GUI, 没有高低贵贱之分, 尽管我们是先学TUI, 再学GUI, 但是这是因为TUI的剩下内容都很难, 毕竟它的专业性摆在这, 比如GCC它们这类编译器, 技术含量可高了. 当然, GUI这边也有Visual Studio.

-------------

接下来我们看看Qt和它的同行们.

对于桌面GUI程序开发(注意, 默认语境是Windows系统下, 毕竟它用户基数大), 我们有一些解决方案:

首先就是Windows API了, 即调用Windows自己的系统接口, 这是一种十分古老的开发方式, 非常繁琐麻烦; 接着就是MFC, 它其实就是微软对于Win32 API的C/C++再封装, 它有很大的影响力, 怎么说吧, 和它配对的事VC 6.0, 目前国内仍有一些教学使用MFC, MFC具有划时代的意思, 它甚至可以以图形化界面的方式拖动要开发的图像化界面, 不过, 后来由于微软推出了自己的C #(C sharp), 从此微软和C/C++就渐行渐远, 基于C/C++的MFC就逐渐不给资源, 现在微软自己也放弃了MFC;  接着就是Qt了, 虽然它和MFC差不多大, 也是C/C++体系的, 但区别是依旧更新(MFC早就不更新了), 也是依旧很有生命力, 也是一种主流的桌面程序开发方案;  后来微软退出了C sharp(可不能念"#"), 于是微软就把大量资源倾斜给了自己的C sharp, 然后推出了Windows Forms(C # 和.net体系), 后来微软又推出了Forms的升级版, WPF以及更后来的UWP, UWP和它的前辈相比, (可能)具有跨平台能力, 目前微软希望这项技术成为市场主流, 不过前景不明. 

近些年来, 还有一个叫"Electron"的技术, "Electron"的技术路线可以说比较不同, 简单的来说, 它内部其实是个浏览器内核, 主要是Chromium, 由于是浏览器, 所以就可以直接使用网页开发的技术, 直接编写HTML/CSS/JS就行了, 优点就是技术路线统一, 开发成本低, 只要内核能跨平台, 网页就自然能跨平台, 很省事. 更新程序换网页就行, 缺点就是和底层调用API的前辈相比, 效率低了一些, 并且由于各个软件都自带浏览器内核, 所以软件大, 运行起来用户体验不是很好, 有原始技术积累的大厂比较喜欢用这套方案.

"Electron"最初是Github官方为开发"atom"文本编辑器而开创的, "atom"的对手就是"Visual Studio Code". 吗结果可想而知, "atom"死了, 不过一方面,  "Visual Studio Code"其实用的也是"Electron", 再加上后来Github被微软收购, 所以现在""Electron""也跟微软姓了.

对于Qt来说, 仍然是很优秀的. 尽管Qt没有UWP那种级别的跨平台(UWP是移动设备也可以用<存疑, 反正微软是这么讲的>), 但无论是Windows, 亦或者Linux, MacOS, 都是支持的. 效率比"Electron高, 在公认层面上的跨平台能力比Windows系列强.

## 背景

Qt的官方描述是一个跨平台的C++图形化界面应用程序框架. 这里提到了一个我们C++学习阶段并不常见的词--框架.   框架是什么? 如果我们之前学过Java, 那可能对框架有较深的认识, 简单地来说, 框架就是程序员中的佼佼者发明出来的, 可以帮助我们这些普通的菜鸡程序员, 可以写出来更靠谱的代码. 对于语言来说, 自由与灵活既是优点也是缺点, 优点就是因为自由, 你可以尽情发挥你的水平, 缺点是对于没有水平的, 乱写容易出错. 框架就能固定程序的大致结构, 可以确保程序开发的下限, 程序主体已经被框架固定了, 我们只需要在这套框架下, 在一些关键细节进行微操, 从而实现具体的功能. 与框架相比, 库也是大佬写的, 但库是被动的, 程序员决定何时使用库, 又怎么用, 框架则是主动的, 程序员配合框架完善细节.

谈到这里, 我们可以杂谈一下C++和Java的生态状况, 形象地来说, C++的生态环境是松散联邦, 军阀割据? 它的生态是割裂离散的, 而Java就是中央集权, 有一些影响力在语言里找不到对手的那种大社区, 比如Spring虽然不在Java标准中, 但实际上已经是公认标准了, C++一方面标准委员会主观性不太强, 另一方面, 由于中央政府集权不行, 所以大家都各自搞各自的框架, 谁也不服谁, 像Qt这种, 在C++内公认的框架, 可以说是十分少见的, 也是近似标准的存在.

Qt, 最开始, 在1991年由挪威的公司 Trolltech 开发, 该公司的具体信息不明, 值得一题的是, 1991年被称为计算机奇迹年, 包括Qt, Python, Vim, OpenGL, Linux..它们都诞生在1991年. 在1996年, Qt进入商业领域, 参与了Linux桌面环境系统KDE的开发, 时至今日, KDE仍旧是Linux最主流的桌面环境之一, KDE的著名也使得Qt在Linux界享有盛名; 2008年, Trolltech 公司被当时的手机巨头Nokia, 即诺基亚收购, 并被诺基亚视为自己旗下的主打技术, 参与对Nokia的塞班手机系统应用程序的主流解决方案. 但随着乔布斯在2007年发布iPhone 1, 宣告移动互联网时代的到来, 诺基亚的手机业务不断被压缩, 最终2011年, Nokia将Qt卖给了芬兰公司 Digia, 并在2016年从Digia中独立出来, 变成了Qt Group Plc，总部在芬兰赫尔辛基, 现在, Qt Group 既负责 Qt 的开发，也提供商业授权和支持。Qt 本身依旧是 LGPL/GPL 开源 + 商业授权 双模式。

接下来看Qt所支持的平台, Qt支持很多平台, 这也正是Qt的优点之一, 按照大类来分, 有四种:

- Windows系列
  Windows是Qt的主场之一, 也是我们之后求职时的一个主要方向之一
- Linux各种发行版, 特别是KDE桌面
  尽管Linux现在主要都是在服务器上运行的, 作为服务器系统来说, Linux其实并不需要图形化界面--图形化反而会影响Linux的服务效率. 但仍存在一些群体, 将Linux装载并作为个人电脑上使用, 在加上Linux在开发者心中具有的特殊地位, Linux仍就演化出了桌面环境及图形化界面. 不过与Windows不同的是, 毕竟最开始桌面环境并不在Linux的设计需求中, 所以Linux并不像Windows那样, 桌面是嵌入到内核中的, 所以桌面环境就是Windows桌面,  而对于Linux来说, 它目前有两条主流的桌面环境, 1) GNOME(使用GTK构建) 2) KDE(使用Qt构建). 与Window相比, Linux的桌面自由度要远比Windows高, 只要你会, 而且能折腾, 那就可以自由配置, 配置成你心中最美的桌面, 但不可否认的是, Linux确实不适合作为个人电脑使用, 个人使用Linux通常意味着可能要与时不时的桌面崩溃, 更新系统驱动异常, 休眠后无法唤醒等玄妙问题和平共处
- Mac 系统
  不甚了解, 还没在Mac平台上开发过, 听说Mac的开发体验很好, 但也有人认为是品牌夸大效应. 只能说我没用过, 还没发言权.
- 嵌入式系统
  这是Qt的另一个主场. 有时, 我们仅需要电脑满足一些基础功能, 比如各种智能家电的控制系统, 工业设备的操作系统, 这种设备不需要太强的硬件性能, 够用就行了, 但对于这些设备来说, 也可能需要一些图形化界面程序, 这对于工业自动化设备尤其常见, 但因为硬件性能的限制, 你不太好往里面装个完整的操作系统 , 所以就需要开发能在弱操作系统甚至无操作系统的机器上运行的图形化界面, Qt就能满足这一点. 不过近年来, 随着硬件的发展, 在这些机器上装一个安卓倒也可以, 然后用安卓的开发方式开发图形化界面程序. 不过Qt仍旧是主流的嵌入式环境图形化界面程序的开发方案. 这也是我们的一个主流就业方向.

Qt 目前已经推出了第六代版本，也就是 **Qt 6**。不过整体来看，Qt 5 和 Qt 6 并没有本质上的差别，再加上企业里依然有大量项目基于 Qt 5，所以我们后续的学习也会以 **Qt 5** 为主。要知道，在商业软件开发中，并不是版本越新越好，关键是要保证产品的稳定可靠。一个版本如果经过了时间的考验，证明足够稳定，那它才适合在生产环境中使用。相比之下，最新版本虽然可能带来新特性，但也可能潜藏着未知的 Bug，因此实际开发的原则是：**选择稳定的较新版本，而不是追逐最新版本**。

另外, Qt在发布时还提供了两种许可证:

- 商业许可: 允许开发者出于商业目的使用 Qt 框架进行开发和发布。商业许可用户不仅能使用更多功能，还能在遇到难以解决的问题时，直接获得 Qt Group Plc 的技术支持。
- 开源许可: 开源项目依据相关开源协议, 直接使用开源的Qt框架

这种 **“开源 + 商业授权”** 的模式在软件开发界很常见。开源能扩大用户群体，提升影响力和市场占有率；商业授权则为用户提供技术支持和保障，带来的收益又能反哺技术发展。典型的例子就是 Linux 的 Red Hat，或者数据库领域的 Oracle。虽然它们收费，但依然有很多企业愿意买单，因为买的不只是软件，而是一份“定心丸”。

对于Qt的优点, 有以下几个方面:

- 跨平台, 几乎支持所有平台.
- 接口简单, 容易上手, 同时作为一种知名框架, 它里面的思想对其他框架的学习也有指导意义
- 它对C++的梦魇, 内存泄露进行了优化, 提供了一种方式, 简化C++内存回收机制, 既没有过分拉低C++的高效率特点, 也带来一种近似半自动垃圾回收方案
- 开发效率高, 能够快速构建应用程序
- 市场占有率高, 用户基数大, 有很活跃的社区环境, 网络上也有很多学习资料
- 支持嵌入式开发, 在嵌入式图形界面开发中依然是主流方案之一。

## 环境搭建与测试

对于Qt的开发环境, 我们理论上需要安装三个部分

- C++编译器(gcc, cl.ext, 注意不是VS这种IDE)
- Qt SDK, 即Qt 软件开发工具包. 需要注意的是, 对于Windows版本的Qt SDK, 已经内置并配置好了C++编译器
- Qt IDE, 即Qt的集成开发环境

注意, 对于Qt SDK确实可以使用外源C++编译器, 但需要进行大量配置, 很容易出错, 因此我们在这里建议就用Qt SDK自带的mingw(也就是Windows的gcc/g++), 注意安装时勾选安装C++编译器选项

对于Qt的IDE, 目前有三种选择:

一是使用Qt官方提供的Qt Creator, 它的特点是不用配置, 安装即用, 所以在下面的学习中, 我们用的也是他. 缺点是Qt Creator有一些小Bug, 虽然开发体验不太好, 但能用 
二是使用VS, 通过在VS上安装Qt的插件, 以及进行额外配置,比如使用合适的SDK, 就可以在VS上进行Qt开发, 
三是Eclipse, 不过他状态不太好, 重量级IDE它比不过JetBrains, 轻量级的比不过VS code, 总之我们Qt其实也不怎么用.  

另外, 需要说明的事, Qt SDK其实自带Qt Creator, 所以实际上我们只要安装一个Qt SDK就行了.

那下面我们就安装一下Qt SDK.

首先如果你直接浏览器搜索Qt SDK的话, 那大概率最顶上会显示Qt Group Plc公司的关于下载的官方文档

![image-20250925220251400](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250925220251400.png)

然后这右上角不就是下载吗

![image-20250925220607524](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250925220607524.png)

我们这里当然是选择社区版

![image-20250925220642043](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250925220642043.png)

之后往下拉, 找到在线下载器链接

![image-20250925220843483](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250925220843483.png)

不过我们使用离线下载

![image-20250925220913753](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250925220913753.png)

我们这里不选择最新版, 而是历史版本

![image-20250925221031602](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250925221031602.png)

Qt按装包分为离线安装包和在线安装包, 从5.15版本开始就只支持在线安装, 为了一步到位, 我们选择最后能支持离线安装的版本5.14.2

![image-20250925221112454](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250925221112454.png)

![image-20250925221132654](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250925221132654.png)

然后下载离线安装包即可

![image-20250925221214804](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250925221214804.png)

安装阶段其实也比较简单, 主体上来说, 就是next

这里需要登录Qt账号, 我们可以去官网注册一下, 好像断网也可以跳过

![image-20250925221445108](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250925221445108.png)

我就不安装在系统盘了

![image-20250925221531090](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250925221531090.png)

接下来要注意, 如果选择内置的C++编译器, 就需要勾选相应的选项

![image-20250925222016717](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250925222016717.png)

然后没什么说的了, 一直下一步, 直接安装就行了, 接下来就进入了主页面

![image-20250925222336164](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250925222336164.png)

不过先不着急, 先关掉

接下来我们建议给装好的Qt, 配置一下环境变量, 不配置不是不能用, 但可能会报奇怪的错误.

环境变量我们已经见过很多次了, 无论是在Linux还是Windows上, 环境变量中的Path目录, 是Windows寻找指令的搜索目录, 换言之, 如果你不把Qt的具体的工具包路径添加到Path中, Windows就意识不到自己身上原来还有个Qt, 它就有可能无法识别Qt的指令.

我们要添加的就是这个目录, `D:\Qt\Qt5.14.2\5.14.2\mingw73_64\bin`, 考虑到安装根目录每个人可能有各自的选择, 所以路径前缀可能不同. 它内部含有Qt相关的可执行程序和动态库.

![image-20250926093621690](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250926093621690.png)

随后添加确认即可

![image-20250926093913334](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250926093913334.png)

安装完成后, 我们就看到电脑上多了几个程序(上面的是另一个版本的Qt 6.5.3不用管)

![image-20250926103737228](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250926103737228.png)

第一个"Assistant5.14.2 (MinGW 7.3.0 64-bit)", 是Qt SDK自带的一个离线文档, 之后我们就以这个文档为依据学习,当然你也可以去官网上看, 但可能需要点手段
第二个"Designer 5.14.2 (MinGW 7.3.0 64-bit)"(Qt设计家), 是一个以图形化方式直接进行界面设计的工具, 可以通过拖拽控件的方式快速生成界面, 不过Qt Creator里面也有它, 我们会直接用Qt Creator里的
第三个"Linguist 5.142 (MinGW 7.3.0 64-bit)"(Qt 语言家), 是一个用来让程序适配各种语言的工具, 它可以让你单独给程序创建一个语言配置文件, 把各种语言都添加进去, 这样用户只要设置一下就能一键变动语言, 以实现国际化, 不过, 对于我们来说, 我们不会重点使用它.
第四个"Qt 5.14.2 (MinGW 7.3.0 64-bit）"就是命令行终端, 这个不说了
第五个"Qt Creator 4.11.1"是Qt的集成开发环境, 将来我们主要使用它.

我们运行Qt Creator 就进入了它的主界面, 哪个帮助实际上就是"Assistant".

![image-20250926110142564](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250926110142564.png)

接下来我们就新建一个项目进行开发环境测试

首先我们在Qt 里新建项目

![image-20250926110537980](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250926110537980.png)

接下来我们使用 Application(应用程序)中的Qt Widgets Application(Qt 组件应用)

![image-20250926111104163](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250926111104163.png)

"Qt Console Application"是写控制台程序的
"Qt for Python - Empty Qt for Python -Window" 是使用Python编写Qt项目, 此外, Qt也支持Java
"Qt Quick Application"(Qt 声明式应用)是近些年来Qt新推出的一种开发GUI的方式, 与之相对的传统开发方式叫做"Qt Widget"

之后选择项目路径和名称, 注意路径不要有中文.

![image-20250926112657793](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250926112657793.png)

接下来我们选择构建系统, 这里有三个选项, 分别是"qmake" "Cmake", "Qbs"

![image-20250926113408777](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250926113408777.png)

恰好的是, 我刚学完Cmake, 像Cmake这种构建系统, 是一种"元编程"技术, 它们会依据底层生成器的不同, 自动的调用平台中的底层生成器, 从而实现跨平台进行项目构建的功能, 关于Cmake的更多内容, 同名的存储库中也有相应的markdown学习文档.

"qmake"那就是Qt 自己的构建系统, "Cmake"不仅Qt可以用, 别的C/C++项目也可以使用, "Qbs"则是Qt新推出的新一代构建系统, 不过我们这里实际上只有两个选项, "qmake" "cmake", "Qbs"是不能选的, 因为"Qbs"用的人非常少, 以至于Qt官方已经放弃了对"Qbs"的维护更新.

这边我们就选择"qmake".

接下来我们进入的界面是Qt Widgets(也可以叫控件) Application 项目的类信息设置向导，简单来说，Qt作为一种框架, 在创建项目时就会帮我们把程序的代码主体自动生成, 在这些生成的代码中, 就包含各种类, 这个界面就是对这些类的信息进行设置

![image-20250926115712289](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250926115712289.png)

我们需要更高的就是其中的基类选项, 有三种选择, "QMainWindow"可以生成一个完整的应用程序窗口, 包括诸如菜单栏, 工具栏, 装备栏等各种控件, "QWidget"就是生成一个控件, "QDialog"负责生成对话框. 现在, 我们作为初学者, 就选择"QWidget".

选择之后, 其它选项也会自动进行适配

![image-20250926120954927](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250926120954927.png)

Qt内置了一个基类, 叫做"QWidget", 这个基类, 正是Qt框架中"框架"二字中的体现, 固定了程序的主体, 然后, 等会儿Qt还会生成一个"Widget", 它会继承"QWidget", 我们就通过对其中基类方法的覆写修改, 去满足实际的工程需要.

"`widget.h`" "`widget.cpp`"那就是class widget的代码文件, 而对于"`widget.ui`"则是程序的关键, 因为它控制者程序中组件的生成以及布局, Qt 会自动把 `.ui` 文件转成 C++ 代码（通过 `uic` 工具），生成对应的控件对象, 这也是Qt里面管理控件的两种方式, 要么是纯手搓C++代码, 要么通过`.ui`以图形化的方式(Qt Designer)先描述想要的控件形式, 然后Qt再进行转换, 如果我们勾选了"Generate form"的选项, 那选择的就是`.ui`的方式.

接下来的界面和语言适配有关, 我们这里就不考虑, 直接跳过

![image-20250926124459607](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250926124459607.png)

接下来选编译器, 由于当初我们只安装了一个, 所以默认就行

![image-20250926124727793](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250926124727793.png)

接下来实际是一个版本控制, 你可以再选择诸如git这类的工具, 然后把项目提交到云上, 我们这里就不选了

![image-20250926124928253](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250926124928253.png)

下面我们也不管那么多, 直接运行这个空项目, 运行点击左下角的绿色三角形即可

![image-20250926144634944](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250926144634944.png)

构建成功后, 就会弹出一个空白的窗口

![image-20250926145257794](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250926145257794.png)

这个窗口就三个内容: 最小化, 最大化, 关闭. 接下来我们就要想办法把这个窗口变得丰富多彩, 解决用户的实际需求.

接下来我们简要分析一下其中的代码:

首先对于`main.cpp`来说, 它的代码十分简单, 一般来说, 我们完全不需要修改`main.cpp`中的内容

```cpp
#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}

```

其中用到了`argc`和`argv`, 将程序的命令行参数实例化一个`QApplication`对象, 对于Qt的图形化界面程序来说, 是一定要有这个对象的. 这个对象的具体内容也不需要我们修改. 接下来实例化一个`Widget`类型的`w`对象, 然后调用方法`show`, 让控件显示出来, 与之对应的方法是`hide`方法就是让控件隐藏, 它们实际上都是继承自`QWidget`的方法, 我们是在`Widget`的父类`QWidget`的基础上进行开发的.

Qt的这种框架形式, 是"面向对象"思想的典范样例, 在下面的学习过程中, 我们也会观察到这一点.

另外, 我们还看到,  `class QApplication`存在方法`exec`, 我们在学习Linux进程替换的时候, 也见过几个`exec`

![image-20241104175407495](https://md-wind.oss-cn-nanjing.aliyuncs.com/md/202411041754728.png)

它们之间什么关系呢? 答案是什么关系都没有, 仅仅是名字上的相同. 就像栈和堆, 数据结构里面有它们, 进程地址空间里面有它们, JVM也有它们, 但它们都是不同的它们.

接下来我们看`widget.h`, 内容也较为简单, 但有些点需要补充

```c++
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H

```

Qt 毕竟还是比较老的, 所以它现在还在用`#ifnde`这种方式确保不会重复包含, 那我们写代码, 当然应该用`#pragma onde`.接下来的命名空间我们先不管. 

接下来主要看对于`class Widget`的声明. 首先可以看到的, 正如我们之前说的那样, `Widget`继承自`QWidget`, 这里随口说一下, Qt 对于类及其头文件的命名习惯一般都是头文件和类名相同, 这一点也好理解. 同时和其他项目一样, 由于头文件可能是嵌套包含的, 所以我们后续写代码的习惯是, 先把Qt的的内置类直接拿过来用, 语法分析器报错再手动包含.

接着我们看到一个宏`Q_OBJECT`, 这个宏展开后会引入一堆代码, 需要说的事, 这个宏和Qt的一个核心概念, 信号和槽密切关联, 将来我们要使用信号和槽也需要在此之前把这个宏写上.

如果我们想看这个宏的具体内容的话, `CTRL` + 鼠标左键点击就行.

在构建函数上, 我们看到它是有参数的, 这是因为在Qt中引入了一个叫做"对象树"的概念, 是一颗N叉树, 我们可以把Qt中的对象挂载到这棵树上. 我们知道, 挂树的时候要父节点, 那这里的`parent`参数作用就是描述这个对象的父节点是谁.

接下来是一个` Ui::Widget *ui;`, 这个就和我们之前看到的`from file(.ui)`密切相关.

接下来我们看生成的`wedget.cpp`

```cpp
#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

```

这里看上去也比较简单, 

`ui_widget.h`是之前我们说的那个`.ui`转换后生成的头文件, 构造函数也没什么好说的, 主要的作用就是让`from file`生成的界面与`widget`关联起来. 析构函数就是把使用的空间还回去.

对于`widget.h`来说, 它的关键要点就是`from file`, 接下来, 我们展开项目文件夹下的`Froms`, 就能看到`widget.ui`文件, 也就是我们说的`from file`, 如果我们点击它, 就会发现来到了设计界面, 这其实就是"Qt Creator" 调用了 "Qt Designer"

这里贴的是另一个版本的Qt SDK(6.5.3)的Creator

![image-20250926164102025](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250926164102025.png)

其中的白色矩阵就是刚在我们看到的空窗口, 左边的那些, 就是Qt 中内置的控件, 所以我们就可以从左边拖拽一些空间到矩阵上, 就可以控制我们的界面了.右下角则是对当前我们选择空间各种属性的展示, 我们可以通过它修改控件的相关属性, 使其表现出特定的行为, 

我们再点回编辑, 就可以看到`weiget.ui`的真实面目, xml标签语言. 这个xml就像一个桥梁, 它可以把我们在设计中设置的空间以文本的形式精确地描述, 然后再讲xml文本交给特定的工具, 转换成C++代码, 在整个过程中, 大家都遵循一定的规则, 因此在信息转化的过程中没有失真, 而是一直反应到了代码上.

与xml相似的标签语言是html, 它们的语法结构非常类似, 都是使用成对的标签来描述信息, 标签之间可以嵌套. xml和html不同的是, 它的标签含义是由程序员自定义的, 我们这里看到的xml文本, 是设计Qt 的大佬们约定的, 对于具体标签的含义, 对于我们来说, 不需要知道. 而对于html来说, 它的标签都是确定的: 有专门的标准委员会进行约定, 所有的浏览器执行的也是这个约定. 

xml的这种功能和特点就类似于我们之前学的自定义应用层协议, 协议的具体内容根据实际需求自由设计, 成为一个桥梁, 让各种各样的结构能够相互进行交互.

接下来我们看一下另一个比较重要的东西, 那就是项目配置文件, 比如`.pro`, `CMakeLists.txt`这种, 它们的作用就是指导Qt 在进行项目配置的细节, 我们先来看`.pro`

![image-20250926174940603](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250926174940603.png)

比如第一行描述的是引入的Qt模块: core 和 gui, 之后, 如果我们使用别的模块, 就可能修改它.   后面的c++11很明显就是约定c++的执行标准, 然后接下来的, 什么`SOURCES HEADERS FORMS`描述了项目的源文件, 

在这里, Qt Creator会自动依据我们的配置自动写出这些文件配置脚本, 这些脚本的功能就是依据不同平台上的工具, 去制定适合项目的开发工具及方式, 去生成对应的生成器脚本, 比如MakeFile, 

另一个版本用的是Cmake

![image-20250926175741018](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250926175741018.png)

那在这里就不解释了. 

对于`.pro`, 会在项目的同目录上创建对应的中间文件夹用来存放生成的最终文件和中间文件, 我们选择在Explorer显示, 就能在资源管理器打开项目

![image-20250926175946540](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250926175946540.png)

这个是用`.pro`的项目布局是这样的

```shell
PowerShell 7.5.3
PS D:\Qt Project\Qt5.14.2> wsl tree .
.
├── Empty
│   ├── Empty.pro
│   ├── Empty.pro.user
│   ├── main.cpp
│   ├── widget.cpp
│   ├── widget.h
│   └── widget.ui
└── build-Empty-Desktop_Qt_5_14_2_MinGW_64_bit-Debug
    ├── Makefile
    ├── Makefile.Debug
    ├── Makefile.Release
    ├── debug
    │   ├── Empty.exe
    │   ├── main.o
    │   ├── moc_predefs.h
    │   ├── moc_widget.cpp
    │   ├── moc_widget.o
    │   └── widget.o
    ├── release
    └── ui_widget.h

5 directories, 16 files
PS D:\Qt Project\Qt5.14.2>
```

使用Cmake的, 则是这样的(部分省略)

```shell
PS D:\Repository\qt-lab\Qt6.5.3> wsl ls -al
total 0
drwxrwxrwx 1 wind wind 4096 Sep 26 15:11 .
drwxrwxrwx 1 wind wind 4096 Sep 26 18:02 ..
drwxrwxrwx 1 wind wind 4096 Sep 26 15:11 Empty
PS D:\Repository\qt-lab\Qt6.5.3> cd .\Empty\
PS D:\Repository\qt-lab\Qt6.5.3\Empty> wsl tree .
.
├── CMakeLists.txt
├── CMakeLists.txt.user
├── build
│   └── Desktop_Qt_6_5_3_MinGW_64_bit-Debug
│       ├── CMakeCache.txt
│       ├── CMakeFiles
│       │   |.....
│       ├── Empty.exe
│       ├── Empty_autogen
│       │   ├── EWIEGA46WW
│       │   │   ├── moc_widget.cpp
│       │   │   └── moc_widget.cpp.d
│       │   ├── deps
│       │   ├── include
│       │   │   └── ui_widget.h
│       │   ├── moc_predefs.h
│       │   ├── mocs_compilation.cpp
│       │   └── timestamp
│       ├── Makefile
│       ├── Testing
│       │   └── Temporary
│       │       └── LastTest.log
│       ├── cmake_install.cmake
│       └── qtcsettings.cmake
├── main.cpp
├── widget.cpp
├── widget.h
└── widget.ui

18 directories, 69 files
PS D:\Repository\qt-lab\Qt6.5.3\Empty>
```

在构建目录下, 我们就能找到生成的`ui_widget.h`, 将其拖入IDE中, 就能查看其中的内容

![image-20250926180924970](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250926180924970.png)

其中就定义了`class Ui_Widget`, 它实际上就是之前我们看到的`Ui::Widget`, 尽管看上去略有不同.还定义了`setupUi`方法的实现.实际是对刚才xml的代码级别描述.

运行构建目录下的`Empty.exe`, 就和我们之前在Qt Creator中运行的效果是一样的.

## 初识Qt

### hello world

在刚才的环境测试中, 我们建立了一个空窗口, 在接下来, 我们将在这个空窗口之上添加文字文本 "hello". 我们将通过两种方式实现这一目标. 1) 通过from file, 即`.ui`文件 2) 纯代码实现

我们先用第一种, 也就是通过from file以图形化方式设计程序界面

首先依旧是新建一个空项目

![image-20250927093529783](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927093529783.png)

接下来我们双击`widget.ui`, 进入设计界面

对于一个文本的显示, 我们可以通过很多控件实现, 在这里我们就选择"Display Widgets"(显示控件)中的"Label"(标签)

![image-20250927094345663](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927094345663.png)

鼠标左键将其拖拽到程序窗口上, 这样, 我们就在GUI上创建了"Label"这个控件

![image-20250927094715223](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927094715223.png)

在这里, 我们可以将它拉大一些, 从而便于文本编辑

![image-20250927094755578](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927094755578.png)

双击它, 就可以对其进行文本编辑

![image-20250927094852357](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927094852357.png)

然后再点一下空白区域, 这个"Label"就算是完成了

![image-20250927095025215](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927095025215.png)

在界面右上角, 我们可以看到对象查看器, 它以树状形式描述了窗口上的控件结构, 其中就包括我们刚刚新增的"Label"

![image-20250927095322828](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927095322828.png)

我们返回编辑界面, 会发现其它文件都没有发生变化, 除了`widget.ui`

![image-20250927095723935](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927095723935.png)

当然, Qt依据该from file生成的C++代码, 也会跟着增加内容

我们从资源管理器打开项目, 并将对应的文件拖拽到Creator中查看内容

![image-20250927100424962](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927100424962.png)

接下来我们就用代码实现同样的需求, 在新建项目之前, 为了避免两个项目在同一个IDE下出现从而造成混乱, 因此, 我们首先关闭上面的项目

![image-20250927103215063](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927103215063.png)

我们同样新建一个空项目, 但这次我们不会再使用from file进行控件设计, 而是会使用`weiget.cpp`

![image-20250927103558789](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927103558789.png)

我们就能看到, `weiget.cpp`中就包含着一个很简单的构造函数, 一般来说, 如果我们想要通过代码构建界面, 通常的选择就是在`class widget`或者`class MainWindow`的构造函数中增加有关控件的代码. 这样的话, 相当于在主函数中的`widget`对象实例化的时候, 就顺便创建了这些控件

```cpp
#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}

```

接下来我们就在构造函数中使用堆的方式来创建`QLabel`对象, 

![image-20250927104801587](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927104801587.png)

但我们发现语法分析器报错了, 这其实也很简单, 因为我们没包含`QLabele`对应的头文件, 直接包含就行了

然而, 在包含的过程中, 我们发现了两种选项

![image-20250927104843994](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927104843994.png)

这就牵扯到了历史原因, 我们之前说过, Qt的历史其实还挺长, 它诞生于1991年, 在那个年代, C++也在发展当中, 还没有形成特定的规范, 所以那个时候的头文件命名风格既有C式的, 也有C++98规定的那种. 那在这里, 我们当然选择更加现代的命名风格, 也就是 `<QLabel>` 

当然, 我们知道, 对象的创建, 既可以在栈上, 也可以在堆上, 那我们这里为什么要在堆上创建对象呢? 这其实就牵扯到Qt 的对象树机制了. 我们知道, 树里面的一个个节点都是用地址联系起来的, 既然对象树就需要地址, 那直接就用堆不更自然吗? 它得到的不就是地址吗? 

另外, 在创建对象的时候, 我们也给它传给参数, `this`, 即`widget`自己的地址, 这个参数的意义就是把`widget`作为`QLabel`的父节点, 让它们建立起依赖关系, 这种依赖关系有助于我们之后统一地对它们进行管理, 毕竟在树里, 一个节点有且只有一个父节点, 除了根节点.

![image-20250927111546277](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927111546277.png)

接下来, 我们就要设置标签的文本, 而在设置的时候, 我们看到函数的参数是这样的

![image-20250927111810682](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927111810682.png)

我们看到它的参数类型是`const QString &`, 这个`QString`是个什么类型? 这就又牵扯到历史了.

Qt 诞生于 C++的早期发展时期, 那时候标准库并不"标准", 各种基本类, 还未发展完成, 比如, C++ std::string 并不好用, 但咱们不能说, Qt 开发的时候找不到好用的字符串类, 所以Qt自己又内部把各种基本类重构了一遍, 于是就有了`QString QVector QList QMap...`, 尽管现在C++ 的标准库如今已经发展完善了, 但由于Qt自己的这些基本类是针对Qt开发特化的, 所以还是Qt的这些类还是比较好用, 比如, 为了适配多种语言, `QString`针对字符编码问题做了特化, 所以我们在使用`QString`时, 不担心字符编码问题, 所以很难出现乱码, 而对于 `std::string`, 就没有这样的特性. 并且, Qt 底层的API接口, 涉及到的类型, 也都是用Qt自己的这些类型, 不过, 也不是不能用标准库中的基础类, 标准库中的基础类和Qt自己的基础类也是有对应的接口可以方便地快速转化的.

我们这里就直接用隐式类型转换, 将常量字符串直接转换成`const QString &`

另外我们这里也不用包含头文件, 因为这些基础类用的很频繁, 所以大概率被其它头文件间接包含, 可以直接使用.

![image-20250927114022625](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927114022625.png)

在这里, 由于没有对控件的位置进行设置, 所以它使用了默认位置--窗口左上角

![image-20250927114139592](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927114139592.png)

### 对象树

在上面的, 通过代码形式让程序界面显示"Hello World"字样的代码中, 我们或许会发现一个问题: 我们在堆上开辟了一片空间, 但却没有将其释放.

![image-20250927120619942](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927120619942.png)

在 C++ 中，资源泄露始终是需要保持潜意识警惕的问题。无论是内存未释放，还是文件描述符未及时归还，本质都是“占用了系统资源却没有归还”。更棘手的是，这类问题往往并不容易在早期被察觉：测试阶段一切正常，在少量服务器上运行也看不出异常，但一旦全面上线，很可能集中爆发，造成整条生产线的宕机。

按照我们的上线流程，若要正式发布一个服务，需要经过测试、预约运维排期、逐级领导审批等一系列步骤。为降低风险，我们通常会采用“灰度上线”的方式。由于生产环境采用负载均衡架构，同一条生产线由多台服务器共同支撑，我们会先选择一台机器进行试运行，确认在真实流量下无异常后，再逐步推广至全量服务器。

然而，灰度阶段能否暴露资源泄露，取决于泄露速度和机器性能。如果泄露缓慢，灰度期间可能完全察觉不到问题，于是顺利全量上线。最糟糕的情况是，在系统运行至某个时间点（往往还是半夜）突然所有服务器资源耗尽，导致整个生产线集体崩溃。

也正因为资源管理在 C++ 中如此关键，许多框架都会在设计层面引入“自动托管”的思想，尽量避免开发者手动去释放资源。例如在前端开发里，浏览器维护着一棵 DOM 对象树，一个节点一旦从树上移除，其子节点也会被自动清理，不需要我们一一释放。类似的理念在很多 GUI 或组件化框架中都能看到，用“父子关系”来绑定对象生命周期，形成一棵结构化的资源管理树。

Qt 也是采用了同样的设计，它在内部引入了一个非常核心的概念——**对象树（Object Tree）**，依靠父子对象的层级关系来自动决定析构顺序，从而帮助我们规避手动 `delete` 所带来的风险。

好的, 我们先回答之前的问题, 对于上面的这份代码, 并不会出现内存泄露. 那下面, 我们将会从理论和实践这两个方面说明这一点.

在Qt中, 有对象树这个概念, 它是一颗N叉树, 可以把界面上的各种组件组织起来.

![image-20250927144200603](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927144200603.png)

比如说, 对于上图中的这个widget窗口来说, 其内部包含着三个控件, 分别是标签, 按钮, 组件列表, 组件列表里还有很多列表项, 于是Qt对应的对象树就是

![image-20250927144721281](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927144721281.png)

如果一个对象被释放, 那么它子节点的对象也会被释放.这样的方便之处就是, 可以把整个对象树看做一个整体,它们将具有相同的生命周期, 这样我们就能在合适的时机, 也就是窗口关闭或销毁的时候, 将他们整个全部释放.  如果我们这里换成栈上的对象, 那么函数结束, 它就被析构, 我们在GUI里不就看不到了? 另外需要说的话, 如果你把已经挂载到树上的对象手动提前释放, 就相当于把以它为根节点的那整棵树进行释放, 并且原先的对象树也会进行相应修改, 因此也不会出现重复析构问题.

```cpp
#include "widget.h"
#include "./ui_widget.h"

#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // QLabel* label = new QLabel(this);
    // label->setText("Hello World");

    QLabel label(this);

    label.setText("Hello World");
}

Widget::~Widget()
{
    delete ui;
}

```

 如果这样写的话, 程序看不到标签, 因为此时label对象随着构造函数的完成就结束了.

另外, 需要强调的一点是, 不要把栈上对象挂到Qt 对象树上, 这是未定义的, 可能造成对栈空间的释放.

接下来就是从实践角度来说明这一点.

下面我们将会新建一个工程, 在这个工程中, 我们将添加自己的`class MyLabel`, 并在其中的析构函数中加上一些信息打印, 就像我们学习C++析构函数时的那样,  并在`wdiget`中使用它, 从而明确看到它确实被析构了.

在又创建一个新项目后, 我们为项目添加类

选择新建文件

![image-20250927152022251](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927152022251.png)

选择C++ Class

![image-20250927152116119](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927152116119.png)

接下来我们设置一下这个类的基本属性, 基类就选择`QLabel`, 由于没有对应的头文件, 所以我们都不勾选

![image-20250927152415214](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927152415214.png)

添加到项目中

![image-20250927152503344](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927152503344.png)

这样Qt 就为我们创建两个文件`mylabel.cpp mylabel.h`, 它们中的一些框架代码已经被直接生成.

如果是5.14.2的Creator 可能不会自动包含头文件`QLabel`, 这里(6.5.3)是自动包含的

![image-20250927152942620](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927152942620.png)

接下来我们在声明上添加`QWidget*`的参数,之后我们就是用这个参数把`MyLabel`挂载到对象树上

![image-20250927153942469](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927153942469.png)

按下`F4`, 可以直接切换到与之对应的`.cpp`文件.

我们通过各个类所继承的基类来实现将它们挂载到对象树的能力, 直白的说, 就是把`parent`作为参数实例化`QLabel`

![image-20250927154514999](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927154514999.png)

接下来我们自定义一个析构函数, 并在其中添加打印信息, 以观察程序的具体反应, 从而验证析构的成功

![image-20250927154803366](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927154803366.png)

接着我们可以双击析构函数, 让光标选中它, 然后按下组合键`ALT + Enter`

![image-20250927154959894](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927154959894.png)

选择"在`mylabel.cpp`中添加定义", 就可以跳到那边并把声明补上

![image-20250927155144795](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927155144795.png)

用什么打印呢? 或许我们就可以用C++的`cout`

![image-20250927155442967](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927155442967.png)

最后我们在`Widget`的构造函数里添加该对象

![image-20250927155800843](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927155800843.png)

然后注意选择应用程序输出, 然后运行程序

![image-20250927161302995](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927161302995.png)

然后我们就看到程序正常启动

![image-20250927161433132](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927161433132.png)

关闭窗口, 就能看到打印内容

![image-20250927161555833](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927161555833.png)

我们看到有日志, 这说明, 析构函数是执行了的, 尽管我们没有手动`delete`, 但最后`widget`析构的时候, 整棵树都被析构了, 于是它也被一同析构了.

不过我们看到, 中文似乎并没有正确打印, 实际上, 各种程序如果出现乱码, 那就只有一个原因, 编码方式不匹配

在计算机中, 对于某个字符的存储原理, 其实都一样: 首先我们先建立一张表, 这个表是个map, 一边是一个数字, 另一边就是一个字符, 存储字符实际上是把代表字符的那个数字存在文件中, 等到真的要用的时候, 再把那张表拿出来, 把数字再翻译回原来的字符.

ASCII 是这样, 它的那张表, 有128 个项, 每个数字代表一个字符. 而对于汉字来说, 它们的存储方式与ASCII码没有本质上的不同--只不过我们的项更多一些--中文的常用字有四千个, 算上各种生僻字, 大概是六万个, 对于计算机来说, 即使是六万也不是很多, 更别说, 日常其实只有四千字. 

问题在于, 表格具体哪个数字对应哪个字符, 不同的组织有不同的标准. 这些不同的表格, 就构成了不同的字符集. 不同的字符集, 同一个字符往往对应不同的数字. 在最开始, 表示汉字的字符集有多种, 但经过不断发展, 其中的绝大多数都被淘汰了, 得到广泛认可的主要有两种 1)GBK   2)UTF-8

GBK主要用于中国大陆, 也能看出来, 是国标. 在GBK中, 使用大小为两个字符的数字来表示一个汉字. Windows简体中文版默认字符集就是GBK
UTF-8的适用范围则更广, 它的设计目标是表示世界上所有的字符,它是所谓"变长(变化长度)"编码: 变长可以自然而言的适应原有的ASCII, 并且, 对于字母语言, 也能节省一些存储空间. 因为它是变长编码, 所以对于汉字来说, 它的编码长度是不确定的, 一般是三个字节, 但也有两个字节和四个字节的. 程序开发也一般使用该编码.

如果我们想要查看上述代码的编码方式, 一种简单, 通用的方式, 就是把对应的文件(文件的编码就是其中文本的编码)使用记事本打开, 在右下角就可以看到编码格式.

![image-20250927175910872](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927175910872.png)

如果显示UTF-8, 当然就是UTF-8, 如果显示ANSI, 其实就是GBK

有一些文本编辑器对于编码也有很多设置, 比如Notepad++

![image-20250927180213667](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927180213667.png)

下面我们回到之前的话题, 既然出现了乱码问题, 那就说明文件和输出终端的编码方式不同, 那在这里应该把文件改成GBK吗? (输出终端没找到编码设置, 即使有, 找起来一定也很麻烦)不行, 因为软件开发, 一般就是UTF-8, 毕竟它是万国码, 适用范围广. (笔者学校教单片机要求使用GBK, 不知道是不是一种行业规范?)

不用担心, Qt 对此早已有所准备, 我们前面说过, `QString`以为我们内置了编码处理, 除此之外, Qt 还有`class QDebug`, 也内置了编码处理, 只不过我们一般不直接写用它, 而是用由他构成的宏`qDebug`, 如下.

![image-20250927181248560](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927181248560.png)

运行

![image-20250927181457600](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927181457600.png)

关闭

![image-20250927181521770](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250927181521770.png)

除此之外, `qDebug`的另一个好处就是, 它在内部设置一个由宏构成的功能开关, 只要我们把宏带上, 这些打印就会自动失效, 这样就不打印出信息了, 所以我们发布软件前就不需要改代码, 直接把宏带上就行, 后面, 我们就把它作为优先打印函数.

-----

通过刚才简单的hello world 我们就能获得对Qt 的不少认识:

1) Qt 中有一个叫做`QLabel`的类, 能够在界面上显示文字
2) `QLabel`的显示文本, 是通过`setText`来设置的, 该函数的接口参数类型是Qt 内部重构的容器类
3) Qt出于历史缘由, 把C++中的许多容器类, 都进行了重新封装, 由此就有了一堆以`Q`开头的容器类, 它们的使用方法与标准库一致
4)  在Qt开发中, 要十分警惕诸如内存泄漏, 文件描述符泄露的计算机资源泄露
5) Qt 为了统一释放界面的空间, 引入了一个叫对象树的概念
6) 所有的Qt基类都有挂载到对象树的能力, 因此我们只要继承对应的基类, 就能让自定义类也能被挂载到树上
7) Qt 的这种基于面向对象的继承思想, 本质上是为了对现有代码在不改变框架的前提下进行扩展
8) 栈上的对象不要挂载到对象树中, 没有挂载到对象树的堆对象, 注意手动释放
9) Qt 的日志输出使用`qDebug`, 它不仅可以内部处理编码问题, 还能在程序上线前通过加宏的方式关闭所有输出
10) 乱码问题本质上是存储时用的字符集和读取时用的字符集不一致造成的

与其他的实际工程相同, 出于对实际生产环境下的兼容考虑, 比如, 机器比较敏感, 本身不允许使用调试器, 问题是概率出现的, 调试器太慢了... 我们在进行实际的程序调试时, 往往不是用调试器进行调试, 而是用日志打印的方式验证程序的运行逻辑与自己预期是否相同. 

### 其它的hello world

接下来, 我们再通过其他其它方式实现hello world.

首先, 我们通过输入框实现hello world.

在Qt中, 输入框主要有两种, 一种是单行编辑框, `QLineEdit`, 另一种是多行编辑框, `QTextEdit`. 这里我们使用单行编辑框, 毕竟"hello world"也挺短的.

单行编辑框在输入控件下

![image-20250928094050625](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928094050625.png)

我们只需要将其拖摘到界面中, 稍微放大, 然后双击编辑文本内容即可

![image-20250928094243034](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928094243034.png)

又或者, 我们可以在选中控件后, 下拉右下角的属性编辑器, 那里也可以进行文本编辑

![image-20250928094528929](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928094528929.png)

运行程序, 我们发现, 程序界面不仅显示出了"hello world"字样, 而且, 还可以直接对其中的内容进行修改

![image-20250928094826372](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928094826372.png)

![image-20250928094847051](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928094847051.png)

同样的, 纯代码方式也可以为界面加上单行编辑框, 具体代码写起来也很简单

![image-20250928095659331](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928095659331.png)

我们看到效果是差不多的

![image-20250928095738303](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928095738303.png)

接下来, 我们再通过按钮实现hello world

在设计界面, 我们可以看到一个`Push Button`, 将其拖拽到界面上

![image-20250928104625030](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928104625030.png)

![image-20250928104733947](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928104733947.png)

运行程序

![image-20250928104802991](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928104802991.png)

我们看到, 生成的界面上有一个写有"hello world"字样的按钮, 并且我们也可以按下这个按钮.

只不过, 这个按钮按下去, 没有什么效果: 因为我们没有进行设置, 那接下来, 我们就对其设置一下, 让按钮按下变化文本. 如果实现这个极值呢? 这就要借助于Qt的另一个核心概念, 信号与槽, 具体的细节我们在后面章节会详细介绍, 在这里, 我们就先简单描述一下.

信号和槽这个概念，其实在我们学 Linux 网络编程时就已经碰到过类似的模式。比如我们有两个对象，一个负责接收数据，另一个负责处理数据。为了让“接收端”在收到数据后能自动触发“处理端”的行为，我们通常会把“处理函数”先包装成一个函数对象（可能是函数指针，也可能是 `std::function`），存放在处理端内部。然后再把处理端的引用或指针交给接收端，使得接收端在某个时刻调用这个函数对象时，就能间接地修改处理端的状态。这里有一个关键点：虽然调用动作是由接收端触发的，但真正的执行时机往往由处理端决定——它可能立刻执行，也可能先缓存下来，等某个条件满足后再统一处理。

Qt 的信号槽机制，本质上就是把这种“函数对象 + 状态转移”的模式规范化了，不过它换了一套更直观的语法来表达“谁发出通知，谁来响应”。

要建立这种通知关系，需要用到一个叫 `connect` 的函数。这个名字我们在 Linux 网络编程里也见过。但 Qt 的 `connect` 和 TCP 的 `connect/accept` 并不是一回事，它们的共同点仅限于“建立一种连接关系”。

在 Linux 里，`accept` 的作用是把底层收到的 TCP 请求上交到应用层，函数返回后本端就认为连接已经建立成功了，并且以文件描述符的形式交给我们继续读写。而在 Qt 里，`connect` 是 `QObject` 提供的一个静态函数，用于把“信号”连接到某个“槽函数”。凡是继承自 `QObject` 的类都具备这个能力，其中就包括 `QWidget`，而 `Widget` 又继承自 `QWidget`，所以我们就能在界面类内部直接调用 `connect` 来建立信号与槽的对应关系。

```cpp
// connect 的推荐语法（函数指针版）
// 用于将 “信号” 和 “槽函数” 建立连接
QObject::connect(
    const QObject *sender,               // 信号的发送者
    PointerToMemberFunction signal,      // 信号函数（一般写成 &类名::信号名）
    const QObject *receiver,             // 信号的接收者
    PointerToMemberFunction method,      // 槽函数（一般写成 &类名::函数名）
    Qt::ConnectionType type = Qt::AutoConnection // （可选）连接方式
);

```

在本项目中, 第一个参数是`ui->pushButton`, 表示谁发出信号, 既然我们按下的事按钮, 那信号自然就由按钮发出, 至于`ui`这个成员是怎么找到`pushButton`的, 等到from file对应的代码生成我们自然可以分析出. 至于`pushButton`这个名字, 那也是有讲究的, 我们重新回到设计界面, 然后看右上角的对象查看器, 就能看到有个叫做`pushButton`的对象

![image-20250928114216959](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928114216959.png)

当我们在设计模式里创建一个控件时, Qt 就会自动为其分配一个 `objectName`属性, 当然我们也可以手动修改这个属性., 当配置系统使用from file 生成对应的C++代码时, 生成的`QPushButton`对象的变量名就是`objectNmae`的字面量. 所以`ui->pushButton`的意思就是从`ui`中访问`pushButton`这个成员变量.

第二个参数, 是`&QPushButton::clicked`, 这其实就是把`QPushButton`中的`clicked`函数指针取出来, `clicked`那就是动词`click`的过去分词表被动, 也就是被点击的意思, 实际上的意思就是, 如果信号被点击, 就会执行`clicked`这个函数, 是按钮被按下时的实际执行函数.

第三个参数, 是`this`, 表示实际对信号做出响应的对象

第四个参数, 是`&Widget::onClicked`, 前缀`on`是介词, 本意在`...`之上, 这里引申为"...的凭借, 由...支撑", 表方式, 这里的意思就是"被按下式所凭借的行为, 方式", 这也是Qt的一种命名习惯, 等会儿, 我们也要为`Widget`增添这个函数.

![image-20250928120829692](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928120829692.png)

![image-20250928120846063](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928120846063.png)

这里, 我们就增加这样的操作: 当按钮被按下后, 将上面的文本切换成"hello qt"

![image-20250928121056551](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928121056551.png)

运行程序

![image-20250928121141528](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928121141528.png)

点击按钮

![image-20250928121156474](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928121156474.png)

再点一下, 还是"hello qt", 看似没有变化, 但实际上是变化的, 只是字符内容是相同的.

那就接下来, 我们微调一下, 实现文本内容替换的效果

```cpp
void Widget::onClicked()
{
    if(ui->pushButton->text() == QString("hello world"))
        ui->pushButton->setText("hello qt");
    else
        ui->pushButton->setText("hello world");
}
```

此时生成的文本就可以做出切换效果

![image-20250928121641375](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928121641375.png)

接下来我们看看from file生成的代码, 看看`Ui::Widget *ui`是怎么找到`pushButton`的, 顺便验证一下, `objectNmae`是不是就是对应对象的变量名.

![image-20250928122303906](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928122303906.png)

我们看到, 其内部确实有一个`pushButton`对象, 接下来, 我们修改一下`ObjectName`, 并做适配, 之后重新运行.

我们回到设计界面, 然后选中空闲, 在属性编辑界面, 更改`ObjectName`的内容

![image-20250928122815396](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928122815396.png)

代码的内容也要进行适配

![image-20250928122933070](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928122933070.png)

这里报错的原因是语法分析器还用着旧的头文件, 重新运行或构建即可

![image-20250928123048330](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928123048330.png)

就能看到变量名也发生了响应的变化

![image-20250928123512049](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928123512049.png)

另外, 我们观察一下该文件末尾的内容

```cpp
namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui
```

我们就会发现, 它在`Ui`这个命名域中定义了一个`class Widget`, 并且, 继承了`Ui_Widget`, 所以说, `Ui::Widget`就是`Ui_Widget`, 自然可以通过它访问`Ui_Widget`中的成员.

那接下来, 我们就再通过代码方式实现之前的效果.

尽管成员的析构可以由对象树来实现, 但我们仍旧需要定义一个`button`成员变量, 用来在不同的函数中访问对象

![image-20250928133644593](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928133644593.png)

![image-20250928133714593](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928133714593.png)

运行

![image-20250928133832476](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928133832476.png)

同样可以达到相同的效果.

在上面的项目中, 我们都分别使用图形化和纯代码方式分别实现了项目, 那在实际的开发过程中, 这两种方式又分别扮演着什么样的角色呢?

实际上, 在实际开发中, 这两种方式都很常用, 我们都需要掌握, 图形化方式主要是用于静态界面, 也就是是说界面的空间不发生变化, 而代码主要是用于动态界面, 往往是点击一个界面, 出来一个控件, 或者点击之后, 控件隐藏. 因此, 在实际开发时, 采取的策略往往是不怎么变动的主界面使用图形化设计, 然后其中的具体细节使用代码来控制.

### 命名规范

在C语言阶段, 我们就知道, 在我们给变量/函数/文件/类起名字的时候, 是有讲究的.   首先, 起的名字要有描述性, 不应该使用诸如`abcd`之类的名字, 并且, 名字应该遵循一定的命名规范, 如果名字中有多个单词, 就要通过一定的方式来区分不同单词.

比如在之前, 我们可能更多的偏好使用下划线`_`来进行单词的分隔, 比如`student_cont`, 这种风格叫做"蛇形命名法", 主要用在C/C++以及部分Python里, 不过, 除此之外的其它语言, 更多的是使用名为"驼峰命名法", 包括Qt框架, 例如`studentCont  QApplication   QWidget`, 并且更具体的说, "驼峰命名法"还分为"大驼峰", "小驼峰", "大驼峰"就是首字母大写, 一般被用于给类起名字, "小驼峰"就是首字母小写, 一般被用在给变量和函数起名.

而在具体的生产环境下, 到底采取哪种命名方法, 需要依据项目的命名风格来定, 即"入乡随俗".

### 文档查询

对于Qt的帮助文档, 可以通过三种方式来使用

第一种, 选中要查询的类名/方法名, 再按下F1

比如我们想了解一下`QPushButton`, 那就可以双击选中它, 然后按下F1

![image-20250928142111868](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928142111868.png)

这个是关闭

![image-20250928142338542](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928142338542.png)

又或者查询`connect`

![image-20250928142439169](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928142439169.png)

第二种方式, 那就是直接点击左边栏的帮助

![image-20250928142533751](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928142533751.png)

这样, 就会以目录名形式, 将Qt的相关信息系统性地进行呈现

![image-20250928142701068](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928142701068.png)

实际上用的不多, 更多是使用查询的那种方式

第三种, 那就是使用"Assistant"

![image-20250928142939686](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928142939686.png)

我们可以, 查看Qt的系统性知识, 或者搜索一下特定内容, 甚至往里面加书签

![image-20250928143142784](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928143142784.png)

在我们的日常工作中, 可能会遇到很多小众的库, 可能它是专注于某个特定的方面, 因此可能网络上没有什么资料, 那此时, 就我们主要依靠的就是官方文档, 当然, 官方主文档大概率都是英文的, 查询英文文档也是我们这一行的必要素养.

### Qt坐标体系

作为一个图形化界面框架, 坐标系这一概念对于Qt来说是很重要的, 当然, 像其它的什么图形化开发方向, 比如图形学, 游戏引擎, 这些都涉及到坐标系这种核心概念. 毕竟我们需要定量描述控件在窗口中的位置, 这离不开坐标系的支持.

首先我们要明确, Qt 所使用的坐标系, 就是我们在数学上常见的平面直角坐标系, 或者说笛卡尔坐标系. 不过Qt用的坐标系和数学上的又略有不同.

在数学中, 横轴是从左往右增长的, 纵轴是从下往上增长的, 也就是右手坐标系

![image-20250928151146253](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928151146253.png)

计算机里的坐标系则是左手坐标系: 横轴从左往右增长, 纵轴从上往下增长

![image-20250928151315197](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928151315197.png)

对于计算机来说, 坐标系的原点就是屏幕的左上角或者是窗口的左上角.

为什么这里说或者呢? 当我们给Qt中的某个控件, 设置位置时所参考的坐标系都是相对于父窗口或者屏幕来说的.

![image-20250928151945553](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928151945553.png)

比如在上图中, 最外层的是屏幕, 然后是`QWidget`, 最后是`QWidget`里的`QPushButton`, 对于`QPushButton`来说, 它的坐标系是依据`QWidget`来建立的

![image-20250928152210110](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928152210110.png)

`QWidget`, 没有父窗口, 此时它的坐标系就是依据整个屏幕来建的

![image-20250928152412770](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928152412770.png)

接下来, 我们新建一个项目, 并创建一个`QPushButton`, 显示"hello world"字样.

![image-20250928153008130](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928153008130.png)

运行, 就能看到按钮出现在左上角, 这里就是原点

![image-20250928153101546](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928153101546.png)

![image-20250928153308307](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928153308307.png)

上面的那部分是系统添加的, 属于系统. 不在`Widget`范围之内. 默认情况下, 按钮出现的位置就是`(0, 0)`. 我们可以通过`move`方法移动控件位置.

![image-20250928153629107](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928153629107.png)

这里的`200 300`其单位都是像素.

我们知道, 显示器本质上是由一堆可以发光的小亮点, 或者小灯泡, 来构成的. 尽管肉眼可能察觉不出来, 但我们可以用最大对焦的手机拍出来.

![image-20250928154828120](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928154828120.png)

又或者, 我们可以打开显示设置, 打开一个显示器, 然后我们就可以看到一个显示器分辨率的设置, 它描述的实际上就是屏幕上像素点的个数

![image-20250928155900933](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928155900933.png)

这里的意思就是水平方向有1920个像素点, 垂直方向有1080个像素点, 很明显, 显示器的像素点越多, 画质就越好, 显示器就越贵.

像`1920 × 1080`的这种规格, 我们一般叫做"1080P", 在这里另一个显示器的规格则是`2560 × 1600`, 也就是我们俗称的"2K".

![image-20250928160317394](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928160317394.png)

现在我们运行程序, 可以看到, 按钮的位置发生了相应的变化

![image-20250928160936692](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928160936692.png)

当然, 我们也可以直接移动`Widget`本身, 只不过他的坐标系是相同于整个屏幕来说的

![image-20250928161209261](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250928161209261.png)

再次运行, 就发现`Widget`也做了相应变化, 这不过我这电脑设置过指定弹窗都出现在屏幕中央, 现在找不到在哪里关了, 截不了屏. 

## 信号和槽

### 基本概念及用法

在对Linux系统编程的学习过程中, 我们也学过Linux中的"信号". 那Qt的信号又是怎样的呢?

在Linux中, 信号"Signal"是系统内部的一种通知方式, 亦或者说是进程间进行通信的一种方式. 其中涉及到信号的"三要素"

信号源, 描述谁发出信号,   信号的类型, 描述发出哪种类别的信号,  信号的处理方式, 初测一个信号处理方式, 在信号被触发的时候自动调用执行. 同样的, Qt的信号, 虽然和Linux信号不是同一概念, 但在设计理念上是类似的. 

在Qt中, 也有信号三要素, 即 1) 信号源, 描述由哪个控件发出的信号, 是按钮发出的, 输入框发出的, 还是其他组件发出的   2) 信号类型, 表示信号的种类, 具体来说, 用户进行不同的操作, 就会触发不同的信号, 如, 点击按钮触发点击信号, 输入框内移动光标, 触发移动光标的信号, 选择一个下拉框, 也会触发对应的信号, 换句话来说, 喜信号的类型, 就是区分用户的不同操作, 毕竟, 图形化界面程序就是需要让用户进行交互, 以满足他的要求, 只有我们知道用户具体的行为是什么, 我们才能写出针对的处理方式. 3) 信号的处理方式, 在Qt中, 我们引入槽(slot)的概念, 用来指代处理信号的函数.

于是乎, 在Qt中就可以通过`connect`这样的函数, 把一个信号和一个槽关联起来, 这样的话, 只要信号触发, Qt就会自动执行槽函数. 槽函数本质上就是一种回调函数. 回调函数的概念相信我们已经在有意或者无意状态下接触过了很多次, 比如, 最早我们学习C语言的函数指针时, 就见到了回调函数, 后来在C++, 我们也见过很多回调函数, 比如仿函数, 也就是operator()重载,, 它其实也算是一种回调函数, 有了仿函数后, 我们在方法或者类中就可以传入方法, 从而实现对库方法中的一些细节问题的调整, 比如改改排序的大小定义之类,  又或者, lambda 表达式, 就是一种更简洁的回调函数.    而在Linux中, 比如信号处理, 线程的入口函数, 多路转接的`epoll`, 都出现了回调函数的概念.

从中我们都可以看到一个规律: 那就是这些回调函数的执行逻辑确实是我们写的, 而且是提前写好的, 但实际的执行时机都是交给别人来决定的, 不需要我们手动再调用.   

在Qt中使用信号和槽离不开一个很重要的函数, `connect`, 注意该函数和TCP socket中的`connect`没有直接关系, 不必过度联想

该函数实际是`QObject`提供的静态函数. 正如我们之前说的那样, Qt中存在着一定的继承关系. 实际上Qt正是通过继承才把众多的类组织到一起的. 

像`QPushButton   QLineEdit   QTextEdit   QRadioButton`... 这些具体的控件类, 它们都有一个共同的父类, 也就是`QWidget`, 而`QWidget`再往上还有一个父类, 那就是`QObeject`, 除此之外, 除了`QWidget`, 像`QMainWindow`这些和`QWidget`并列的类也继承自`QObject`, 所以, 几乎可以说, Qt的类里面都有`QObject`, 也都都能使用`connect`.

![image-20250929084600194](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250929084600194.png)

`connect`的函数签名如下

```cpp
// connect 的推荐语法（函数指针版）
// 用于将 “信号” 和 “槽函数” 建立连接
QObject::connect(
    const QObject *sender,               // 信号的发送者
    PointerToMemberFunction signal,      // 信号函数（一般写成 &类名::信号名）
    const QObject *receiver,             // 信号的接收者
    PointerToMemberFunction method,      // 槽函数（一般写成 &类名::函数名）
    Qt::ConnectionType type = Qt::AutoConnection // （可选）连接方式
);
```

尽管有五个参数, 但实际上第五个参数我们也可以看到, 提供了缺省值, 实际上, 第五个参数很少使用. 前四个已经够用了.

第一个参数`sender`, 即信号源, 描述了哪个控件发出了信号, 第二个参数`signal`, 即信号的类型, 描述了用户具体的交互行为, 第三个信号`receiver`, 描述信号的处理者, 第四个参数`method`描述`receiver`具体的处理函数.

下面我们就写代码体验一下: 我们将实现这样的一个功能: 界面上包含一个按钮, 用户点击按钮则关闭窗口.

![image-20250929092850394](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250929092850394.png)

现在按钮已经写出来了, 运行, 我们发现程序运行正常, 只不过按钮按下没有反应: 因为我们没有`connect`

"CTRL + 鼠标左键点击", 就可以查看某个类的定义, 我们看到`QPsuhButton`继承自`QWidget`

![image-20250929093357789](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250929093357789.png)

![image-20250929093420404](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250929093420404.png)

而`QWidget`又继承自`QObject`

![image-20250929093504559](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250929093504559.png)

"ALT + ←方向键"可以回退到上一个文件

![image-20250929093742623](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250929093742623.png)

我们拿子类的指针传到父类的形参上, 我们知道, 这当然是可以的

![image-20250929094537356](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250929094537356.png)

我们知道, 英语没有未来时变位, 对于未来将要发生的事情, 在编程中一般直接用动词原形, 比如, 此处的"click", 是动词原形, 表示"将要按下", 它的意思就是说, 如果你做了某件事, 那么这个按钮就会被按下, 更准确的说, "click"是槽函数, 它调用时, 就相当于点击了一下按钮, 而对于"clicked", 使用了过去分词形式, 是信号函数, 表示按钮已经按下了, 发出"按钮被按下"的信号. 另外, 我们也能看到, 函数前面的图标也表示了该方法的类型, 像一个"斜放城墙"的图标, 表示这是一个槽函数, 而另一个不太好描述的图标, 则表示这是一个信号函数.

Creator 17.0.1 的语法分析器明显优化了, 因为`connect`第二个参数不会出现槽函数的预选项, 因此在这里用旧版

![image-20250929095628817](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250929095628817.png)

我们这里自然是要传一个信号函数

![image-20250929095735716](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250929095735716.png)

这里我们也要求, `connect`的前两个参数一定要是匹配的, 既然第一个参数是`QPushButton`类型, 那么第二个参数就应该是`QPushButton`中的方法.

第三个参数, 描述提供槽函数的对象, 也就是`this`, `Widget`也是`QObject`子类, 自然也能传递

![image-20250929100049185](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250929100049185.png)

最后第四个函数, 则是`Widget`中的`close`函数, 更准确的说, 是`Widget`从`QWdiget`那里继承下来的`close`

双击选中`QWidget`, `F1`帮助, 选择`public slots`

![image-20250929100754924](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250929100754924.png)

![image-20250929100810480](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250929100810480.png)

![image-20250929100911685](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250929100911685.png)

看名字我们就能看出来, `close`表示关闭窗口

于是整句`connect(button, &QPushButton::clicked, this, &Widget::close)`的意思就是, 针对`button`进行点击, `Widget`就会关闭.

此时我们按下按钮, 窗口就会关闭

![image-20250929101231233](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250929101231233.png)

写下`connect(button, &QPushButton::clicked, this, &Widget::close)`, 可能有人还有一些问题, 比如, 我怎么知道`QPushButton`里面怎么有一个`clicked`信号函数, 亦或者`Widget`里面怎么有一个`close`槽函数的? 一句话概括就是, 我怎么知道Qt里面的各种类有哪些信号和槽呢?

其实这个问题我们在上面已经无意中解答过了, 那就是翻阅帮助文档. 下面, 我们就用旧版SDK中的`Assistant`找找`clicked`.

进入索引, 我们直接搜索`QPushButton`

![image-20250929103549546](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250929103549546.png)

然后朝下翻我们发现竟然没有`Signals`这个项, 后面都是具体的使用细节

![image-20250929103808930](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250929103808930.png)

这怎么回事? 要注意, `QPushButton`它上面还有一个父类呢, 既然我们代码编对了, 那就说明, `QPushButton`里面肯定是有`clicked`的

我们看最前面的项

![image-20250929105420318](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250929105420318.png)

`Inherits`自然不必说, 继承的意思, 意思就是`QPushButton Class`是从`QAbstractButton`那里继承下来的, 而对于`Inherited By`则是被动语态的构成, 我们知道, 英语中被动语态的构成是

```txt
be（系动词/助动词） + V-ed（过去分词） + by + 执行者
```

例如

```txt
The carrot was eaten by the rabbit.   胡萝卜被兔子吃了
```

不过很多情况下, 不需要表明"被谁..."这一概念(可能大家都知道), 所以把上面的句子改的更简洁一点就是

```txt
A carrot was eaten.
```

这其实就是非谓语动词中过去分词作主语补语(表语)的用法.

所以`Inherited By`的意思就是

```txt
The QPushButton Class was inherited by the QCommandLinkButton. QPushButton 被 QCommandLinkButton 继承
```

那下面我们就去`QAbstractButton Class`那边看看, 我们知道`abstract`是抽象的意思, Qt用的`abstract`一般是逻辑上的抽象, 而不是C++语法的那种抽象(有纯虚函数). Qt中会提供很多按钮, 这些按钮之间存在一些"共性"内容, 就把这些共性的东西, 放到`QAbstractButton`里, 然后其它的按钮直接继承就行, 这样就不用再考虑按钮的公共功能, 只需要对具体的按钮进行一些个性化的设计

![image-20250929112003001](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250929112003001.png)

往下翻, 我们就能看到`clicked`

![image-20250929112049489](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250929112049489.png)

我们看到, `clicked`还带一个缺省参数, 这个参数在`QPushButton`里是用不到的, 所以目前我们也不需要管. 后面的`pressed`是鼠标按下, `released`是鼠标释放, 这其实就是把"按下按钮"这个动作拆分了, `toggled`则是状态切换, 比如复选框的勾选与否.

我们点击`clicked`, 就可以跳转到对应的细节说明

![image-20250929112810907](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250929112810907.png)

`emitted`是发出的意思, 那这里就是"触发一个信号", 后面`when`引导的定语从句就描述了信号的触发时机, 是按钮被激活的时候, 比如, 先按下, 然后再松开, 在鼠标指针处在按钮里的时候.   并且, 按下组合键  或者`click animateClick`被调用的时候, 信号也会被触发.

`connect`其实还有一个远古版本

```cpp
bool QObject::connect(
    const QObject *sender,
    const char *signal,
    const QObject *receiver,
    const char *method,
    Qt::ConnectionType type = Qt::AutoConnection
);
```

这个远古版本我们现在已经不用了, 对比一下我们使用的`connect`

```cpp
QObject::connect(
    const QObject *sender,               // 信号的发送者
    PointerToMemberFunction signal,      // 信号函数（一般写成 &类名::信号名）
    const QObject *receiver,             // 信号的接收者
    PointerToMemberFunction method,      // 槽函数（一般写成 &类名::函数名）
    Qt::ConnectionType type = Qt::AutoConnection // （可选）连接方式
);
```

我们看到, 这两个`connect`的第一个和第二个参数是不同的, 在原来, 它们的类型都是`const char*`, 而现在则都是`PointerToMemberFunction`, 另外这个`PointerToMemberFunction`其实也不是类型, 而是一种语义标注. 

在以前, 为了能让取出的函数指针适配`const char*`, 我们要在外面包上一层宏, 把它转成`const char*`, 否则类型不匹配, 比如:

```cpp
connect(button, SIGNAL(clicked()), this, SLOT(close()));
```

这其实就牵扯到Qt`connect`函数底层的一个设计思路的发展.

其实, 最开始, Qt为了实现`connect`的功能, 它相当于自己又建立了一张功能更强大的虚函数表, 在底层的`QObject`类中, 维护着一张`map`表, 这个表的左边是常量字符串, 右边是函数指针

```cpp
std::unordered_map<std::string, std::function<void()>> funcMap;
funcMap["foo"] = &foo;
funcMap["bar"] = &bar;
```

每次, 其它类继承`QObject`之后, 都要相应的对表的内容进行手动修改或者增加内容, 所以说像虚函数表, 只不过实际上Qt的虚函数表应该没有这么简单, 可能还有其他内容.  

而`SIGNAL`和`SLOT`的作用就是把输入的参数解释成常量字符串传参. 等到实际要执行的时候, 才通过常量字符串找到`map`那一头的函数指针进行执行. 

所以以前的`connect`是一种纯粹基于字面量进行函数对象的检索存储和执行, 函数指针只是最后被执行一下, 它并不参与检索和存储阶段.

现在版本的`connect`则与之不同, 它就是基于指针来进行函数对象的传递的, 它没有字符串转换的中间过程, 所以你在传参的时候传的就是地址, 不是字面量, 所以你需要带上`&QPushButton::`这种东西, 一方面是你要取地址, 另一方面是你要跨域取地址, 所以你必须要指定域名, 否则找不到.

并且`PointerToMemberFunction`实际上也不是类型, 函数类型很多, 他不能提供一个明确的类型, 所以使用的是模版或者泛型编程的技术, 也就是说, 它们两个是模版类型.

我们同样`CTRL` 点击`connect`, 就能分别找到`connect`的不同重载版本

![image-20250929131740868](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250929131740868.png)

这里面用到了一个类型萃取的C++操作, 就是利用成员函数的类型反推出类的类型.

首先, 需要明确的是对于类的成员函数, 其函数指针的类型也是含有类的信息的, 只不过我们之前没有应用场景, 所以很少会强调这一点, 在此既然遇到了, 我们就详细演示一下

```cpp
#include <iostream>
#include <cxxabi.h>

class a{
    public:
    void f(int){};
};

int main() {
    int status;
    char* realname = abi::__cxa_demangle(typeid(&a::f).name(), 0, 0,
    &status); std::cout << realname << std::endl; std::free(realname);
}

```

如果直接打印`typeid(&a::f).name()`, 其显示的是经过编译器修饰过的符号, 不是可读的 C++ 类型名, 所以我们这里用反修饰语句还原

```shell
[wind@Ubuntu test]$ clang++ main.cpp 
[wind@Ubuntu test]$ ./a.out 
void (a::*)(int)
[wind@Ubuntu test]$ 
```

类型萃取其实也很简单, 那就是直接通过成员函数的类型直接把对应类的类型直接取出来

```cpp
#include <iostream>
#include <cxxabi.h>

class a{
    public:
    void f(int){};
};

// 一个模版类
template<typename Func> struct FunctionPointer;  

// 针对类成员函数作偏特化
template<typename R, typename C, typename... Args>
struct FunctionPointer<R (C::*)(Args...)> {
    using Object = C;                       // 提取类类型
    using ReturnType = R;                   // 提取成员函数返回类型
    using Arguments = std::tuple<Args...>;  // 提取参数列表类型
};


int main() {


    int status;
    char* realname = abi::__cxa_demangle(typeid(&a::f).name(), 0, 0,
    &status); std::cout << realname << std::endl; std::free(realname);

    FunctionPointer<void (a::*)(int)>::Object i;  // 取出其中的Object类型
    realname = abi::__cxa_demangle(typeid(i).name(), 0, 0,
    &status); std::cout << realname << std::endl; std::free(realname);

    return 0;
}

```

```shell
[wind@Ubuntu test]$ clang++ main.cpp 
[wind@Ubuntu test]$ ./a.out 
void (a::*)(int)
a
[wind@Ubuntu test]$ 
```

所以 `const typename QtPrivate::FunctionPointer<Func1>::Object *sender` 最终会被展开为 `QPushButton* sender`，也就意味着 Qt 在编译期就能知道信号来自哪个类，并据此进行类型检查，而不像旧版那样只能在运行时通过字符串查表。

### 信号和槽函数的扩展

在上面的例子中, 我们所使用的信号和槽函数都是Qt中内置的, 尽管说Qt内置的信号和槽函数已经很多了, 但正所谓"计划赶不上变化", 有时我们就需要为Qt增加自定义的信号和槽函数.

我们先说自定义槽, 槽函数的自定义其实很简单, 在Qt 5之后, 槽函数的定义和普通的成员函数一致, 你可以把它完全当场普通的成员函数来写.

![image-20250929154307656](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250929154307656.png)

![image-20250929154322215](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250929154322215.png)

运行

![image-20250929154343822](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250929154343822.png)

![image-20250929154400187](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250929154400187.png)

之前我们说在Qt 5, 可以直接把自定义槽函数当做普通成员函数来写, 而在之前, 比如Qt 4, 则必须在声明前加上`public/private slots`, 如下

![image-20250929154659670](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250929154659670.png)

这里就相当于Qt 在C++上增加了自己的标准. Qt 是一个元编程技术, 即基于我们的代码, 生成其它代码, 为此它可能需要通过某些关键字, 来判断下面的代码是干什么的, 有什么意义. 不过在现在, 不写这个也行. 

对于槽函数的自定义, 还有另一种方法, 是利用图形化界面定义组件, 而用代码去描述组件的行为.

首先, 我们进入设计界面, 创建一个按钮

![image-20250930084331426](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930084331426.png)

现在我们已经有了`pushButton`这个对象

![image-20250930084534627](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930084534627.png)

这样我们就可以通过`ui->pushButton`访问到他, 于是就能写出诸如这样的代码

![image-20250930085007593](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930085007593.png)

不过这并不是我们想说的方式, 其实上, 连`connect`也可以在设计界面那里创建

我们回到设计界面, 鼠标右键控件

![image-20250930085229385](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930085229385.png)

选择转到槽, 这就相当于写好了`connect`的第一个参数, 指定了信号源

![image-20250930085647812](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930085647812.png)

这个界面, 就相当于是在写信号类型, 它会以继承形式呈现, 我们选择`clicked`

之后就能发现, 它`widget.h widget.cpp`中出现了一段代码, 这就相当于默认`this`是`widget`的`this`, 并且也把槽函数的框架给搭好了, 等着你填具体细节.

![image-20250930090256526](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930090256526.png)

![image-20250930090324731](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930090324731.png)

这个函数名不能改动，毕竟这是在设计界面那边生成出来的名字，你如果手动改掉，设计界面那边就对不上号了，等于前面的流程白做。而且这个命名方式其实背后是有一套机制的 —— 一旦你通过设计界面为某个控件（比如 `pushButton`）创建过一个槽函数，那么这个控件的其它信号也可以不用再去设计界面重复同样的步骤，直接手写函数就行。比如 `pushButton` 除了 clicked，还有一个 `pressed` 信号，那你可以直接写一个 `on_pushButton_pressed()`，它同样会被当成 `pushButton` 的 pressed 槽函数来处理。**甚至**，就算你还有一个控件叫 `checkBox`，设计界面里你根本没给它“转到槽”，你直接写 `on_checkBox_toggled()`，它也照样认。这种设计的出发点很明显，就是为了简化重复操作，省得你每次都点来点去。不过这种机制也有缺点，就是**太“靠名字猜”了**，看起来直观，但语义模糊，在多人协作的时候很容易产生误会，语法分析器也会提醒这种写法有潜在风险。

![image-20250930090900274](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930090900274.png)

![image-20250930093059275](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930093059275.png)

![image-20250930093113231](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930093113231.png)

实际上, 我们打开from file生成的代码文件, 多了一段`connectSlotsByName`

![image-20250930100038208](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930100038208.png)

这里的意思自然就是在`Widget`对象中执行上面的机制.

那下面, 我们就稍微改动一下函数名, 让它不满足匹配规则

![image-20250930101311546](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930101311546.png)

此时我们就能看到, 一方面, 按钮按下不再有反应, 另一方面, 在应用程序输出这里也会提示没有匹配到的信号, 也就是说它进行了匹配, 但匹配失败了

![image-20250930101515823](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930101515823.png)

---------

下面我们就说说如何自定义信号函数.

需要注意的是, 自定义槽函数, 对于我们日常的程序设计非常关键, 开发中大部分情况都是需要自定义槽函数的, 毕竟用户的需求千千万, 与之对应的满足需求的业务逻辑那就自然需要特别设计. 

而对于信号函数，它当然也很重要，但这种重要更像“空气”——你离不开它，但它并不会成为主要矛盾。GUI 和用户之间的交互方式本来就很有限，无非是点按钮、勾复选框、拖滑条，这些完全可以被穷举。所以在 Qt 中，自定义信号本质上只是对现有信号的重新组织或者语义重命名，并没有创造出真正“全新的交互来源”。

如果把视野放到游戏开发，尤其是自由度高的探索类游戏，这种“信号”概念就会完全变味。我们可以做一个类比：

1. Qt 的信号是**被动的**，只有当用户执行了某个明确动作（比如 clicked）之后，系统才会发出信号，由槽函数来处理；
2. 而游戏里的“触发”往往是**主动扫描出来的**，比如每一帧都在检测“玩家是否靠近道具”“是否在空中并且速度低于某个阈值”“是否处于受击状态且与墙壁接触”。这些条件根本不是“别人发信号我来接”，而是程序不停地问“有没有满足某个条件”。

因此，Qt 的信号槽更像是“广播式通知”，而游戏中的事件触发更像是“持续条件判断”。前者可以列举清楚，后者几乎无穷无尽。也正因为如此，GUI 程序可以闲着没事不执行，而游戏程序哪怕什么都没发生，也要不停地跑逻辑扫描，所以才格外吃性能。

我们之后的学习过程中也不会涉及到自定义信号, 所以, 在此我们只是仅仅简要地说一下概念和用法.

在下面我们将会满足这样的需求, 界面上有复选框和一个按钮, 复选框勾选与否将会影响按钮的行为.

首先对于信号函数的声明, 与槽函数略有不同, 槽函数的声明已经可以不在前面写`public/private slots`, 但对于信号函数来说, 他必须要在前面写`signals:`, 并且, 我们只写一个函数声明就行了, 函数的具体实现将由Qt生成, 而且这种"具体实现"对于我们来说是一个"黑箱状态", 完全无法干预, 我们也看不到实现的具体内容, 从而完全无法干预这个过程.  另外, 信号函数的返回值必须是`void`, 参数则无所谓, 并且也支持重载.

我们添加自定义信号和槽函数

![image-20250930115149786](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930115149786.png)

去设计界面拖两个控件

![image-20250930113910217](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930113910217.png)

`emit`是个关键字, 表示发出后面信号函数的`signal`, 那这里的逻辑就是, 按下按钮,(触发按下的信号, 执行`onPushButton`) 如果复选框没有选中, 则标题变为"nothing", 否则是"title", 说实话, 写到这里感觉表示得还是不够形象,有点鸡肋,  在这里, 其实可以完全不用自定义信号, 不仅变复杂, 而且完全没必要复杂

![image-20250930115428258](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930115428258.png)

运行

![image-20250930120119277](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930120119277.png)

![image-20250930120132468](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930120132468.png)

实际上, 你不带上`emit`也行, 之前似乎说过, 直接调用Qt的内置信号函数就相当于在代码上发出了信号. 这对于自定义信号来说也是相同的, 实际上`emit`的作用更像是给程序员看的, 不是给机器看的. 发信号的具体内容都在型号函数的实现中, 相似的, 内置信号函数前面加`emit`其实也没什么关系.

### 带参数的信号和槽

前面我们说的都是不带参数的信号和槽, 实际上, 信号和槽也支持带参数, 同时也支持重载,. 简单的说, 是发射信号的时候传个参, 处理信号的时候受到同样的参数, 那就意味着, 槽和对应信号的函数参数列表在类型上是要匹配的, 为什么说类型是匹配的呢? 原因就是, 参数个数可以不匹配, 比如信号有五个, 槽有两个, 只要那两个类型对得上就行了, 剩下的三个参数就相当于被丢弃了. 不过反过来是不行的, 参数可以丢弃但不能凭空造.

下面我们还是创建一个新的项目, 并在其中添加自定义的槽和信号函数.

![image-20250930130448218](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930130448218.png)

![image-20250930130412689](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930130412689.png)

![image-20250930130429004](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930130429004.png)

运行

![image-20250930130536598](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930130536598.png)

那这传参到底有什么用呢? 主要来说, 它能起到复用代码的效果, 比如有多个逻辑, 实际上整体一致, 但涉及到的数据不同, 那此时就可以通过参数复用代码, 并且, 还可以在不同的场景下传入不同的参数.

现在我们再来一个按钮

![image-20250930130843686](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930130843686.png)

![image-20250930131100713](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930131100713.png)

运行

![image-20250930131138684](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930131138684.png)

此时按下不同的按钮, 标题也就不同

除此之外, Qt很多内置的信号, 也是带有参数的, 不过这些参数不是我们自己传的. 比如`clicked`, 它有两个类型

![image-20250930133818512](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930133818512.png)

布尔类型表示当前按钮是否处于选中状态, 这个选中状态对于`QPushButton`, 但对`Check Box`有用

那下面我们就具体看看上文所说的参数不匹配情况

先是信号函数两个, 槽函数一个

![image-20250930145412556](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930145412556.png)

![image-20250930145424275](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930145424275.png)

我们看到, 可以正常的运行

![image-20250930145455286](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930145455286.png)

但你反过来, 自然是不行的

![image-20250930145656907](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930145656907.png)

这里就直接提示参数是不匹配的

![image-20250930145822890](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930145822890.png)

Qt 之所以对函数的参数进行了弱匹配(类型必须匹配, 个数信号比槽相等或多就行). 这是为了应对这种情况: 同一个槽函数, 绑定了多个信号, 如果严格要求数目一致, 那么信号函数我必须进行适配, 要求就变高了, 或者说耦合度太高了, 牵一发而动全身, 那写代码不难受吗?

类型我们就不去试了. 

### Q_OBJECT

我们在代码中可以看到这样的一个宏

![image-20250930151547727](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930151547727.png)

在Qt中, 如果要让某个类能够使用信号槽, 即让这个类定义信号和槽函数, 则必须在类的一开始写下`Q_OBJECT`这个宏.

![image-20250930151817301](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930151817301.png)

它的内部也是各种宏. 最终展开是很复杂的代码, 这里我们自然不会说, 毕竟我们现在的阶段只是学习Qt, 而这段代码其实对我们使用Qt没什么帮助.

这里特别说这个宏, 是想强调, 想要让类能够使用槽和信号, 那就一定要带上这个宏.

注释掉再编译的话, 他也会直接提示你

![image-20250930152237678](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20250930152237678.png)

不过我们实际上也不用太过注意. 毕竟在Qt里面, 新的类是在Qt引导下搭建主体框架的, 所以会依据你的选项自动带上`Q_OBJECT`, 不过知道他是干什么的, 对于Qt开发是个很基础的知识.

### 信号槽设计理念的杂谈

 Qt 这种用信号和槽来驱动图形界面开发的方式，其实在整个 GUI 行业里算是少数派。大多数 GUI 框架，包括网页开发在内，处理用户事件基本就是直接塞一个回调函数进去，事件来了就直接调用，就像我们在 Linux 网络编程里常见的那种“裸回调”。

Qt 底层当然也是回调，但它没有把回调暴露出来，而是硬生生抽象出一套“信号-槽”机制。那为什么 Qt 要绕这么一层呢？

1. 解耦合做得极致：信号只负责“发”，槽只负责“收”，彼此完全不用知道对方是谁。
2. 天然支持多对多：一个信号可以 connect 到多个槽，一个槽也可以接多个信号。这点是绝大多数直接回调式 GUI 做不到的，它们基本都是一对一绑定。

正是因为这个“多对多 + 解耦”的设计，Qt 在组织组件行为时可以写得非常灵活，一个信号可以同时驱动 UI、日志记录、动画，也可以轻松做模块复用。所以，Qt 的信号槽看似“啰嗦”，但本质上是为了更强的可扩展性和可维护性。

不过，也需要承认另一面。有人说过，一个工程应尽量降低复杂度。Qt 当初强调信号槽可以多对多连接，确实是一大特色。但在长期的实际开发中，大家逐渐发现，大多数情况下根本用不到那么复杂的连接关系。绝大部分信号只连一个槽，两个都算少见，真正写成一对多、多对多的反而容易让逻辑变得难以追踪。

所以如今来看，多对多连接已经不能再算 Qt 的核心卖点，至少并不常用于日常开发。如果要评价 Qt 的优点，跨平台能力和封装层次清晰，反而比“信号槽强大”更具有说服力。

### 信号槽的断开

信号槽能连接, 那自然也有断开, 也就是`disconnect`, 它的用法其实比较少, 绝大多数情况, 信号和槽一旦连接之后, 就不再管了. 主动断开往往是把信号对应到另一个槽上, 并且原来的槽和现在的槽在功能上是不兼容的-- 否则一对多也可以. 它的具体用法和`connect`一致

我们在这里就简单创建一个项目, 稍微演示一下: 我们将引入两个按钮, 它们都能修改标题的内容, 默认情况下第一个按钮将是有效的, 但在按下第二个按钮之后, 第一个按钮就将失效, 而第二个按钮将生效.

我们这里还是先加两个按钮

![image-20251002100410435](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251002100410435.png)

![image-20251002101754198](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251002101754198.png)



 ![image-20251002101647928](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251002101647928.png)

运行之后, 就会看到, 按下第二个按钮之后, 第一个按钮就不起作用了

### lambda槽函数

槽函数其实也是可以使用`lambda`表达式的, 关于`lambda`表达式我们也在C++11那里说过. `lambda`正好就符合槽函数的一般特性: 作为回调函数, 代码里一次性使用, 用完就不管了. `lambda`本身的语法设计也能让槽函数写的更加方便.

我们还是新建一个空项目, 只不过这次我们不用再`widget.h`里写函数声明了

![image-20251002104659707](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251002104659707.png)

![image-20251002104732269](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251002104732269.png)

如果你想使用父作用域的变量, 那自然就要进行变量捕获

![image-20251002105028058](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251002105028058.png)

![image-20251002105052049](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251002105052049.png)

如果你想使用更多的外层变量, 自然也可以用`[=]`的方式全捕获进来.

不过, 对于`lambda`的变量捕获, 有些需要注意的问题, 那就是使用的变量一定要是有效的才行.

在上面的代码中, 我们使用的值捕获, 所以真正需要在意的是`button`指向的那片空间, 而我们知道, 这片空间在对象树上, 所以可以认为生命周期等同于整个窗口, 窗口关闭才会释放, 所以我们可以较为放心的用.  对于`this`指针来说, 尽管它指向的对象`widget`是在栈上的, 但它所在的栈是`man`函数, 所以也没有什么操心的. 

我们操心的是, 由于槽函数是关联信号的, 而信号的触发时机是用户决定的, 所以要确保在用户能操作界面的整个过程, 其对应的槽函数中变量都是可被访问的, 比如如果这里你使用的是引用捕获, 那么捕获的`button`是位于构造函数中的栈变量, 但用户是在构造完成周再去交互界面的, 这样的话, 就容易出问题. 在加上控件使用的都是指针, 赋值捕获和引用捕获差不多, 所以我们一般用的都是值捕获, 这也是一种行业默契吧.

另外需要注意的是, `lambda`是C++11才引用的, Qt5及更高版本, 默认使用的就是C++11或者更高版本, 但目前市面上其实还有一些公司使用Qt4, 那此时就要在项目配置文件里指定使用C++11. 对于`.pro`就是`CONFIG ++ c++11`, `cmake`就是`set(CMAKE_CXX_STANDARD 11)`

![image-20251002111010137](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251002111010137.png)

![image-20251002111143129](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251002111143129.png)

## 常用控件

控件对于Qt开发是一个核心概念. 了解常用的空间, 对于我们来说是至关重要的.

控件当然也是一个发展的过程:  在最开始, 并没有控件. 设计图形化界面就是靠"手画"的: 把显示器的内容视为一个画布, 通过调用操作系统的API, 在这张画布里画各种东西, 最终把界面画出来. 这种开发方式, 已经很古老了. 用它开发出来的程序, 也很具有时代感.

![87c736706de883d780e86b585d9095d7](https://md-wind.oss-cn-nanjing.aliyuncs.com/87c736706de883d780e86b585d9095d7.jpg)

比如文曲星, 它有一个名叫"LAVA"的平台, 这个平台用的就是这种图形化开发方式.

这种纯手画的方式就是第一代的图形化设计方案.

很明显, 这种方式的开发效率实在比较低, 于是自然就引入了"控件"这种概念. 早期的控件比较简单, 数量也很少, 比如HTML, HTML有很多标签, 不同的标签就会被浏览器渲染出不同的效果. 比如我们可以去找老网页看看.

![image-20251002132759926](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251002132759926.png)

我们看到, 还是比较原始, 毕竟这是早期的控件

现在, 互联网已经有了长足的发展, 也出现了很多成熟的控件库

![image-20251002133852209](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251002133852209.png)

这个网站叫做`Element UI`, 是饿了么出品的 前端组件库.

Qt的控件还不是这么现代, 不过我们也可以通过细节设置进行控件优化, 达到差不多的效果, 不过具体的优化细节我们不会细说, 本文主要是从技术层面来说Qt. 近年来, Qt的母公司还推出了一个叫`Qt Desiggn studio`的产品, 用它做出来的界面美观程度就是业界最领先的一档. 不过`Qt Desiggn studio`和我们现在的`Qt`差别有些大.

![image-20251002135039615](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251002135039615.png)

我们真正的工作场景一般是公司的美工为程序进行界面设计, 然后我们再照着他们的样子来做界面.

### QWidget

我们首先要提的控件就是`QWidget`, 在之前我们曾略微说过Qt的继承体系--所有的空间都继承自`QWidget`类, 所以掌握`QWidget`的使用方法, 就相当于掌握Qt控件体系中, 通用的部分.

打开一个项目, 在设计界面中, 我们就可以看到`QWidget`的各种属性.

![image-20251002155518012](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251002155518012.png)

我们可以通过文档来一一了解. 在此, 我们只学习其中一些比较常用, 重要的属性即可.

#### enable

| API          | 说明                                              |
| ------------ | ------------------------------------------------- |
| `isEnable()` | 获取控件的可用状态                                |
| `setEnable`  | 设置控件是否可用, `true`表示可用, `false`表示禁用 |

首先是`enable`, 这个属性描述控件是否可用, 可用, 就是可以捕捉到用户的交互行为, 不可用, 或者说禁用, 那就是忽略用户的所有交互行为, 换句话来说就是用户怎么点, 那也没反应, 在外观上, 这种控件也会变灰. 

如果一个控件被设置为禁用, 那么它的子元素也会被禁用.

![image-20251002161036153](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251002161036153.png)

![image-20251002161049008](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251002161049008.png)

现在运行程序, 按下按钮, 我们发现窗口的标题变为"enable"

![image-20251002161132035](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251002161132035.png)

现在去掉注释, 重新运行, 此时按钮在外观上变灰, 点击也无反应

![image-20251002161238901](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251002161238901.png)

下面, 我们在一个项目, 其中将会牵扯到两个按钮, 一个按钮将打印日志, 另一个则负责切换第一个按钮的可用状态

进入设计界面, 拖入两个按钮

![image-20251002163111901](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251002163111901.png)

我们发现, Qt对于`ObejectNmae`的自动命名风格是, 第一个使用控件名, 第二个使用控件名_2, 以此类推

![image-20251002163404846](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251002163404846.png)

这样的话, 之后我们就可以使用`ui->pushButton    ui->pushButton_2`的方式访问到它们, 但是我们说, 命名应该具有含义, 所以一般也会手动改一下`ObjectName`, 在这里, 我们就把第二个按钮改为`pushButtonEnable`

![image-20251002164117885](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251002164117885.png)

![image-20251002164658001](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251002164658001.png)

运行

![image-20251002164717851](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251002164717851.png)

![image-20251002164748333](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251002164748333.png)

![image-20251002164815384](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251002164815384.png)

![image-20251002164827777](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251002164827777.png)

#### geometry

`geometry`即几何. 听起来有些抽象? 实际上, 你可以把它理解成四个属性的统称: 横坐标, 纵坐标(位置), 长, 宽(尺寸). 注意, 具体描述的是控件左上角的位置.

![image-20251003101415582](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003101415582.png)

 与之相关的API, 有若干个, 在这里我们只是拿出最常用的两个

| API                                                          | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| `geometry()`                                                 | 获取控件的几何属性. 返回一个`QRect`, 其中有`x, y, width height`这四个参数 |
| `setGeometry(QRect)   setGeometry(int x, int y, int width, int height)` | 设置控件的位置和尺寸, 可以直接设置, 也可以用四个参数单独设置 |

`Rect`是`rectangular`(矩形)的缩写. 在Qt中, 也对一些几何概念进行了封装, 比如`QPoint`(点), `QRect`(矩形). 由于这些对象中的属性比较少, 所以在传参的时候一般按照值的方式进行传参, 而不是用引用.

下面, 我们就写一个程序, 通过四个建来控制一个矩形的位置属性

在设计界面, 我们创建五个按钮, 其中一个作为矩形, 而剩下四个, 则分别作为上下左右这四个方向键.

![image-20251003103913337](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003103913337.png)

然后, 我们对四个方向键分别创建对应的槽函数

![image-20251003103857983](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003103857983.png)

![image-20251003105104760](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003105104760.png)

其它的方法, 也是相同的模式

运行

![image-20251003105453196](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003105453196.png)

![image-20251003105746183](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003105746183.png)

我们发现, 它确实动了, 但好像不是按照我们想的那样动的: 它似乎是右下角不变, 仅仅是在移动左上角, 这样的话, 在移动过程中并没有保持住原有的形状, 而是发生了形变.   这是因为我们使用的是`rect.set`系列函数, 它在设置过程中, 尺寸也会发生变化.

如果不想让尺寸发生变化, 而仅仅是实现平移的效果, 就需要使用第二种`setGeometry`

![image-20251003110443713](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003110443713.png)

重新运行

![image-20251003110531550](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003110531550.png)

于是我们就实现了平移的效果

![image-20251003110603032](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003110603032.png)

接下来, 我们再写一个用来请假的恶搞程序: 点击批准, 那就批准了, 点击驳回, 按钮会跑.

![image-20251003114831488](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003114831488.png)

在设计界面, 我们引入一个标签, 两个按钮

接下来, 我们为这两个按钮增加不同的槽函数

![image-20251003122016655](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003122016655.png)

运行

![image-20251003122029226](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003122029226.png)

![image-20251003122101496](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003122101496.png)

![image-20251003122111733](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003122111733.png)

![image-20251003122128821](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003122128821.png)

我们能不能做得更绝一点呢? 现在是点击后才移动, 如果我点击但不松开, 它就不移动

![image-20251003122420265](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003122420265.png)

所以我们可以把信号改成`pressed`, 也就是按下时就触发信号, 而不是按完后

我们之前说过图形化的自动连接的机制了, 这里, 我们就把函数名改一下即可, 别忘了头文件那边也要改

![image-20251003122714090](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003122714090.png)

运行

![image-20251003122744227](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003122744227.png)

能不能做得更绝一点: 鼠标靠近按钮, 不按下, 按钮就跑? 当然是可以的, 但是以我们现在的知识水平, 还不行, 等讲到Qt事件这个知识点之后, 我们再回来改.

#### WindowFrame

其实, Qt中窗口坐标原点体系分为两种, 分别是不包括`WindowFrame`和包括`WindowFrame`. 我们之前说的坐标都是不包含`WindowFrame`的.

对于我们编写的窗口来说, 除了窗口本体来说, 其实还会多一些东西出来

![image-20251003125523344](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003125523344.png)

窗口的外围会有一圈细边, 上面还有一个窗口标题. 这些东西, 我们就叫做`WindowFrame`, 或者说, 窗口框架. 这是操作系统自己给窗口加的东西, 你也可以对其进行设置, 进行隐藏, 比如--打游戏全屏的时候.

这样的话, 其实对于参考系的原点, 就有了两套标准

![image-20251003130147652](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003130147652.png)

我们之前使用的API, 就是`geometry`系列, 它的原点就是不带`WindowFrame`的, 也就是以窗口本体左上角为原点的, 而`FrameGeometry   setFrameGeometry`这些接口, 它们的坐标系就是带上`WindowFrame`的, 也就是说, 它们的原点是框架的左上角.

关于位置, 还有许多API, 在此我们就不介绍了. 我们需要注意的事, 在使用它们时, 要注意, 使用的到底是哪个坐标系.

下面, 我们写一个程序来看一看

![image-20251003131127971](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003131127971.png)

运行之后, 我们发现它们似乎没有什么区别? 这是为什么呢? 其实也是因为我们打印的时机实在构造函数中, 也就是说, 我们在对象还没有完全实例化之前进行了打印, 此时框架还没被加上, 所以没有区别.

为此, 我们可以加一个按钮, 按钮按下再打印

![image-20251003131626773](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003131626773.png)

![image-20251003131726546](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003131726546.png)

从运行结果来看, 我这里应该没有那条细边, 只有窗口标题, 这其实是平台差异, 但不论怎么说, 窗口标题是有的.

在Qt 5上, 我们就能看到是有边框的, 宽度是一像素.

![image-20251003133234063](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003133234063.png)

#### WindowTitle

`windowTitle`和`setWindowTitle`可以对窗口的标题进行读写. 需要注意的是, 这里说的窗口是顶层窗口, 也就是说, 这个窗口是对象树的根节点, 是有`WindowFrame`的那种窗口, 

![image-20251003134817173](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003134817173.png)

但如果是子`QWidget`, 比如一个按钮, 仍可以对其调用`setWindowTitle`, 但不会有实际效果

![image-20251003135122390](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003135122390.png)

没有效果, 也无报错. 所以在设置标题的时候, 别把对象找错了.

#### WindowIcon

该属性描述顶层窗口的图标.  图标就是程序运行时在任务栏上的图标

![image-20251003145939577](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003145939577.png)

比如, 这些图标

相比之下, Qt 的默认图标就不太美观

![image-20251003150146055](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003150146055.png)

此时, 我们就可以通过调用`setWindowIcon(const QIcon& icon)`, 其中的`QIcon`, 自然就是用来描述图标内容的对象类型. 相比之下, `windowIcon`获取图标对象就很少用, 除此之外, 它也是只对顶层窗口有效. 值得注意的是, 我们会在栈上创建这个对象, 可能有人问为什么不在堆上创建然后挂到对象树上? 从设计理念上来说, 对象树上的对象都是控件, 而`icon`它的职责是把资源文件从磁盘上读到内存中, 然后再写到窗口的属性中, 所以它们不是一种对象, 因此`icon`他不应该挂载到对象树上; 从实际操作中, `QIcon`也没有继承自`QObject`, 所以它也根本没有挂载到对象树上的能力.

既然是图标, 当然要有图片, 这里就有一张图片

![Furina](https://md-wind.oss-cn-nanjing.aliyuncs.com/Furina.jpg)

这是一张AI图, 虽然看起来比较真. 它的本机文件地址是"D:\Users\wind\Pictures\Saved Pictures\Furina.jpg"

![image-20251003152423534](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003152423534.png)

需要注意的是, 这里不应该使用`windows`的路径分隔符, 因为在C/C++中, 默认情况下会将`\`视为转义字符, 比如`\n \r`. 当然如果非要用, 可以使用`\\`, 这样就可以第二个`\`就会对第一个`\`也进行转义, 使得第一个`\`失去转义的能力, 从而被视作路径分隔符.或者你可以使用C++11引入的`raw string`, 这样就不会进行任何转义, 比如`r("d:\furina.jpg")`. 这里我们当然使用最简单直接的方式

运行

![image-20251003153208872](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003153208872.png)

当然, 这张图比例不太对, 效果不太好. 任务栏也是相同的图标

---------

但对于这种代码来说, 有一个很严重的问题, 那就是硬编码了, 它使用了并不靠谱的绝对路径, 程序最后是要发布到用户的电脑上的, 这样写肯定是不行的. 为此我们有两种办法. 

一是把我们所需要的资源文件放在安装目录下. 所谓安装目录, 顾名思义, 就是程序安装的路径, 也就是说, 在程序安装到用户的电脑上时, 也把所需要的资源文件同样安装进去, 然后尽管用户的整体文件结构整体是未知的, 但安装的根目录是由我们确定的, 我们知道根目录下的文件结构, 因此就可以使用相对路径的方式找到资源文件. 具体怎么办, `cmake`中其实讲过, 这里就不说了.

另外一种, 把资源文件中的二进制数据直接读出来, 写到可执行程序本体里面, 它的缺点就是如果资源文件很大, 小图标当然没什么, 要是视频音频就会很大, 程序的编译时间会显著变长, 本体大小也会显著变大, 运行时就会变慢. 

这里我们讲的就是第二种.

具体地来说, 我们将会在项目中新建一个`xml`文件(后缀是`.qrc`), 用资源文件初始化它, 然后Qt会把这个`xml`转换成字符数组代码, 最后把这个字符数组编译到程序里面.

首先我们添加新文件, 使用`Qt Resource File`模版

![image-20251003155237603](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003155237603.png)

它会自动加上后缀的

![image-20251003155406081](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003155406081.png)

版本控制选默认就行

此时我们就会进入这样的一个界面

![image-20251003155513227](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003155513227.png)

这里有一个“添加前缀”的按钮。说到前缀，就要讲讲 `qrc` 的设计思路：它希望对资源文件进行有效管理，因此建立了一个虚拟的文件系统。当物理资源在 `.qrc` 中被注册时，`.qrc` 会记录它的实际物理路径（通常使用相对路径以保证跨平台性）。开发者可以为每个文件分配一个逻辑路径作为唯一标识符，这样在代码里就可以通过逻辑路径访问资源。构建时，Qt 会根据 `.qrc` 找到对应的物理文件并将其打包到程序中，从而形成逻辑路径到物理文件的映射关系。

采用文件路径形式作为逻辑标识符的好处是，它天然具有层次性，更便于统一管理资源，也让程序内部的资源层次更加清晰。当然，如果你问我为什么要额外抽象出一个 `qrc` 虚拟文件树，我只能说大概率是为了方便：逻辑访问和物理布局分离。对于 `qrc`，你完全可以把资源文件集中放置，只依赖虚拟路径理清逻辑，只要注册后不要随意移动它们即可。而物理层面的文件布局容易被破坏，但虚拟目录实际上就是 `.qrc` 文件本身的文本，除非你修改了这个文件，否则逻辑路径不会改变。

那在这里, 我们就先点击一下它

![image-20251003171727720](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003171727720.png)

我们看到, 它自动生成了一个前缀, 但我们的资源其实很少, 所以不必要太在乎, 我们直接使用一个`/`就行了

![image-20251003171833729](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003171833729.png)

接下来, 我们注册文件, 点击添加文件, 注意, 资源文件必须放在项目文件夹(或子文件夹)下(不然不和绝对路径差不多吗), 并且再注册之后, 就不能再移动了.

![image-20251003172255782](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003172255782.png)

这样, 在虚拟文件树下就有了我们的文件

![image-20251003172330521](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003172330521.png)

接下来, 我们就可以直接使用这个虚拟的路径访问资源文件

![image-20251003172810425](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003172810425.png)

它是以`:`为前缀开头的, 后面的就是虚拟路径(前缀 + 文件名)

接下来, 我们打开项目, 去看一下资源文件对应的生成代码

![image-20251003173554270](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003173554270.png)

然后我们就能看到一个无符号字符类型的数组

![image-20251003173643733](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251003173643733.png)

资源文件再怎么说,也是二进制构成的, 直接把他们的内容读出来并编译到可执行程序, 自然不怕丢.

#### WindowOpacity

`opacity`是不透明的意思, 所以很明显, 这个属性就是用来描述控件的不透明性的.   比如Windows 7的毛玻璃效果, 那就是基于半透明而做出的效果. `windowOpacity`属性在数值上是一个`float`, 其数值介于`0~1`之间, `0.0`表示全透明, `1.0`表示完全不透明.

下面, 我们仍旧是通过代码直接演示: 我们将引入两个按钮调节窗口的透明度

![image-20251004115229780](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004115229780.png)

运行

![image-20251004115401086](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004115401086.png)

不过, 在输出这里, 似乎有些不太对: 这很明显不是以0.1为间隔变化的

![image-20251004115452357](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004115452357.png)

产生这种原因并不奇怪, 这源自C/C++对于浮点数的存储机制

```shell
[wind@Ubuntu test]$ touch test.cpp
[wind@Ubuntu test]$ clang++ test.cpp 
[wind@Ubuntu test]$ cat test.cpp 
#include <cstdio>

int main()
{
    float i = 0.1;
    printf("%.10f\n", i);

    return 0;
}
[wind@Ubuntu test]$ ./a.out 
0.1000000015
[wind@Ubuntu test]$ 
```

早在我们学习C语言的时候, 我们就说过

![image-20251004120907109](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004120907109.png)

浮点数分为符号位, 有效数字, 指数部分这三类. 第一个有效数位的权为`0.5`, 第二个是`0.25`, 第三个是`0.125`....由于有效数字部分长度是有限的, 所以对于某些数字, 比如这里的`0.1`, 在内存中实际上存的并不是`0.1`, 而是一个很接近于`0.1`的数.

所以写代码的时候, 对于浮点数的比较应该使用误差的形式, 而不是直接比较. 当然也存在一些精确表示的方式, 但效率就比较低.

-------

除此之外, 需要说明的是, `setWindowOpacity`这个函数对于参数其实有内部检查, 也就是说如果输入的参数超出`0~1`的范围, 这个参数就会被舍弃, 函数本身也不会进行任何操作.  因此, 从功能性的角度来说, 我们在外面不加检查也是可以的.

但实际开发中, 我们还是推荐, 即使你明知道所用的参数内部有参数检查, 那你也在外面检查一下. 这就涉及到"防御性编程"的观点. 我们不能依赖于别人的安全检查, 自己也必须要有安全检查. 这样, 即使别人出问题了, 也不会出现太大问题. 要知道, 实际开发我们是一个项目组. 可能这边写个模块, 给那边用, 那边也写一个模块, 给我用, 对于这种情况, 我们就要抱着"不怕一万, 就拍万一"的心态, 对于输入模块的参数进行自我检查, 当然, 写模块的, 在内部也要有安全检查. 这样就形成了一种双重检查, 它的好处就是可以让项目更加模块化, 我写的或者我使用的模块, 不依赖于另一方的操作, 即使真的出问题了, 也不好在我身上找问题.

#### cursor

`cursor`, 描述鼠标光标的样式. 比如, 我的系统光标是这样的

![image-20251004130456977](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004130456977.png)

与之有关的, 有三个API, `curson()`可以获取当前空间的光标属性, 以`QCursor`对象的形式返回. `setCursor(const QCursor&)`则是对光标进行设置, 除此之外, 还有静态函数`QGuiApplication::setOverideCursor(const QCursor&)`则是设置对象树级别的光标, 就是整个对象树上的控件光标形式都被设置成了这样, 对象树子节点上的控件原来的光标属性会被覆盖. 我们这里重点演示前两个.

在设计界面, 我们就可以直接对光标属性进行设置

![image-20251004131253502](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004131253502.png)

我们这里就改成"禁止"

  ![image-20251004135749064](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004135749064.png)

当然也可以用代码的形式来改

![image-20251004140754362](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004140754362.png)

这里就是对窗口的光标进行了设置

![Cursor_pgFUZTA79A](https://md-wind.oss-cn-nanjing.aliyuncs.com/Cursor_pgFUZTA79A.png)

同时我们`CTRL`点击`WaitCursor`, 就能看到更多样式

![image-20251004141057975](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004141057975.png)

当然, 我们也可以使用自己的图标作为光标. 比如我们可以搜索"阿里巴巴 矢量图标库"

![image-20251004141253670](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004141253670.png)

其中就有很多图标

![image-20251004141342845](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004141342845.png)

这里直接下载就行

![image-20251004141424812](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004141424812.png)

保存到项目文件夹下, 然后和上次`icon`那样, 我们添加资源文件

![image-20251004141607350](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004141607350.png)

前缀还是简单一些

![image-20251004141646991](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004141646991.png)

再将文件注册

![image-20251004141719601](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004141719601.png)

在Qt中, 也有很多类型可以访问图片, 常用的类型是`QPixmap`.

运行

![image-20251004142201720](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004142201720.png)

不过我们看到, 图片有些大, 此时也很好解决, `QPixmap`是支持图片缩小放大的. 我们可以使用`QPixmap`的`scaled`成员函数, 构造出一个更改大小的新图片对象.

![image-20251004142926125](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004142926125.png)

第三个参数是保持比例进行改变, 具体按照什么规则改变这里就不说了

![image-20251004143037550](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004143037550.png)

另外, 需要说的一点是, 我们看到光标是一个图片, 但点击时很明显是一个点, 那么这个点究竟是图片上的那一个点呢?(这个点术语叫做"热点") 不同版本的Qt对此有不同的处理, 对于这里的Qt来说, 它默认中心选择的是图片的几何中心. 不过我们也可以手动控制

这样写, 就是把图片的左上角作为"热点"

![image-20251004143536594](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004143536594.png)

#### font

`font`即字体属性, 是有关一系列字体属性的集合. 在Qt中, `QFont`是描述字体对象的类型.其中包含许多子属性

<table border="1" cellspacing="0" cellpadding="6">
  <tr>
    <th>属性</th>
    <th>说明</th>
  </tr>
  <tr>
    <td><code>family</code></td>
    <td>
      字体族, 如 
      <span style="font-family: 微软雅黑;">"微软雅黑"</span>, 
      <span style="font-family: 仿宋;">"仿宋"</span>, 
      <span style="font-family: 楷体;">"楷体"</span>
    </td>
  </tr>
  <tr>
    <td><code>pointSize</code></td>
    <td>
      字体大小, 单位像素  
      (<span style="font-size:12px;">12px 示例</span>, 
      <span style="font-size:18px;">18px 示例</span>, 
      <span style="font-size:24px;">24px 示例</span>)
    </td>
  </tr>
  <tr>
    <td><code>weight</code></td>
    <td>
      字体粗细, 取值范围为[0, 99], 数值越大, 字体越粗  
      (<span style="font-weight:50;">细 50</span>, 
      <span style="font-weight:75;">粗 75</span>)
    </td>
  </tr>
  <tr>
    <td><code>bold</code></td>
    <td>
      是否加粗, <b>加粗</b> 相当于weight为75, 不加粗相当于weight为50
    </td>
  </tr>
  <tr>
    <td><code>italic</code></td>
    <td>
      是否<i>倾斜</i>
    </td>
  </tr>
  <tr>
    <td><code>underline</code></td>
    <td>
      是否带有<u>下划线</u>
    </td>
  </tr>
  <tr>
    <td><code>strikeOut</code></td>
    <td>
      是否带有<s>删除线</s>
    </td>
  </tr>
</table>
对于我们来说, 字体设计一般不由我们亲自进行, 我们只需要把美工的设计设置进去就行了, 如果公司比较小, 没有他们, 那可以去参考别人的设计, 比如

我们可以打开一个网站, 进入开发者模式(F12)

然后我们选择这个按钮

![image-20251004152954613](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004152954613.png)

把光标移到文本上

![image-20251004153106786](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004153106786.png)

然后就能看到了.

我们首先在设计界面进行设置, 拖入标签,

![image-20251004153325505](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004153325505.png)

展开`font`

![image-20251004153350575](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004153350575.png)

后面两个就不管了, 实际不是和文本有关的

![image-20251004153534275](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004153534275.png)

![image-20251004153546455](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004153546455.png)

对于设计界面来说, 优点就是实时展示效果, 但它只能进行静态设置, 如果我们想程序运行过程中更改字体, 此时就只能用代码了.

![image-20251004154310965](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004154310965.png)

#### toolTip

当我们想为空间增加描述性文本内容的时候, 就可以使用`toolTip`, 把光标移到控件上, 描述性文本就会出现一段时间, 然后消失.

比如这个, 当然这个是如果不挪开, 一直显示

![image-20251004155841960](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004155841960.png)

语法提示, 其实也是`toolTip`

![image-20251004160031670](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004160031670.png)

与之相关的,主要使用的有两个接口, `setToolTip setToolTipDuring`, 前者设置文本, 后者设置显示的时间, 单位是`ms`, 获取不常用.

进入设计界面, 我们引入两个按钮

![image-20251004160528595](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004160528595.png)

这样的话, 一个是停留三秒, 另一个就是四秒

![image-20251004160910087](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004160910087.png)

#### focusPolicy

这个属性需要稍微理解一下. 该属性用于描述控件获取到焦点的策略.

这里就要谈一谈焦点这个概念. 一个界面, 可能会有很多组件, 这些组件怎么知道用户是和它交互的? 而不是和别的组件交互的呢.  这就要求控件获取焦点,  从用户的角度来说, 就是用户以某种方式选择了一个控件.

比如我们打开浏览器的开始界面

![image-20251004164940972](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004164940972.png)

刚打开时, 不论键盘怎么按, 输入框都没有反应

只有我先选中输入框, 比如通过鼠标点击的方式, 这样搜索框才能接收到我的输入内容

![image-20251004165118050](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004165118050.png)

或者我们创建一个全新的Qt项目

![image-20251004165221875](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004165221875.png)

我们按一下方向键, 就选中了不同的控件

![image-20251004165259915](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004165259915.png)

现在再按一下`TAB`键, 此时再按下方向键, 切换的就是这两个按钮

![image-20251004165440968](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004165440968.png)

再按一下`TAB`, 切换的就是这些按钮

![image-20251004165519346](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004165519346.png)

控件被选中的过程就叫做控件获得了焦点. 而`focusPolicy`属性描述的就是可以通过哪些方式去选择控件, 在上面, 我们用的方式分别就是鼠标点击和键盘的某些特定键.

在线笔试时的反作弊机制也和焦点有关.  你进入在线笔试的链接, 进入页面后, 这个页面就是获得了焦点, 如果你切到别的地方, 页面就会失焦, 后台就能检测出来. 并且在线笔试的反作弊机制其实已经非常成熟, 比如它也会通过摄像头检测你答题时的状态, 答题是的状态在后台都可以分析得很清楚, 所以在这里要说的一句题外话就是, 可以不会写, 题做的不好也是有可能入职的, 但作弊是态度问题, 查出来, 一方面不会提醒你, 另一方面, 一定会拒绝你, 甚至可能终身拉黑你, 永不录取.

与`focusPolicy`有关的常用接口有两个: `focusPolicy()   setFocusPolicy(Qt::FocusPolicy)`, 其中`Qt::FocusPolicy`是一个 枚举类型, 枚举了获取焦点的几种策略.

- `NoFocus`    控件不会接受焦点, 比如纯粹用来显示文本的label标签
- `TabFocus`    可以通过`TAB`获取焦点
- `ClickFocus`    可以通过鼠标点击获取焦点
- `StrongFocus`    既可以通过`TAB`, 也可以通过鼠标, 是默认策略
- `WheelFocus`     新增内容, 在`StrongFocus`的基础上增加了鼠标滚轮的获取方式, 不常用

接下来, 还是做实际项目

进入设计界面, 创建四个输入框, 即Line Edit

![image-20251004171617654](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004171617654.png)

运行程序, 就会采用默认策略`StrongFocus`

![image-20251004171740210](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004171740210.png)

此时无论是,鼠标点击还是`Tab`, 都可以选中它们

![image-20251004171921921](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004171921921.png)

按下`Tab`, 切换到下一个

![image-20251004171949646](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004171949646.png)

`SHIFT TAB`, 选择上一个

![image-20251004172027331](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004172027331.png)

接着, 我们对第二个输入框进行设置, 策略改为`NoFocus`

![image-20251004172142402](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251004172142402.png)

此时第二个输入框就无法被选中

如果改成`TabFocus`, 虽然鼠标无法选中, 但`TAB`可以选中. `ClickFocus`则是反过来.

#### styleSheet

`style`是样式的意思, `sheet`原意是"纸", 这里引申为"清单", 所以`styleSheet`就是样式表的意思.它的作用是通过类似于`CSS`的方式来设置控件的样式.

那这里就涉及到两个概念, `CSS`和样式. `CSS`全写是"Cascading Style Sheets", 翻译为"层叠样式表", 最开始它是网页前端开发用于描述界面样式的一种技术, 这种技术已经经过了多年的发展, 非常成熟, 能把界面设置得很好看, 于是Qt就以这项技术为基准, 发展出了自己的QSS技术. `styleSheet`就是QSS的一部分, 对于QSS技术的细节, 我们在之后再说. 对于样式这个概念, 一句话来说, 就是定量描述界面样貌的形式, 计算机是数据处理的机器, 所以自然是要定量的进行描述.

接下来, 我们就使用`styleSheet`来设置标签的样式

![image-20251005104725361](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005104725361.png)

在我们选中标签后, 在属性界面就可以看到`styleSheet`属性

![image-20251005104924379](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005104924379.png)

点击省略号按钮, 就能弹出编辑窗口

![image-20251005105004323](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005105004323.png)

或者右键控件, 改变样式表

![image-20251005105040673](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005105040673.png)

`styleSheet`的格式和CSS类似: 按照键值对的形式设置, 键和值之间使用":"分隔, 键值对和键值对之间使用";"分隔.

![image-20251005105820505](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005105820505.png)

![image-20251005105838991](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005105838991.png)

![image-20251005105958167](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005105958167.png)

样式表中的具体属性和选项, 可以通过文档, 搜索"Qt Style Sheet". 具体细节在后续的QSS专属章节我们再谈.

接下来, 我们再写一个项目: 通过代码形式实现窗口"light, dark"模式的切换, 一般来说, "light"也就是日光模式, 背景是白色的, 字体是黑色的, "dark"也就是夜间模式, 背景是黑色的, 字体是白色的.

我们拖入一个文本框, 比如"Plain Text  Edit", 再拖入两个按钮, 分别作为切换到亮色主题和深色主题的按钮.

![image-20251005111430100](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005111430100.png)

注意不要拼写错误

![image-20251005112058164](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005112058164.png)

运行

刚开始

![image-20251005112114341](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005112114341.png)

按下"亮色主题"按钮

![image-20251005112145621](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005112145621.png)

按下"深色主题"按钮

![image-20251005112207170](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005112207170.png)

我们看到, 这里实际上出现了三种模式, 因为Qt程序的默认窗口背景并不是白色, 而是有点泛灰的感觉, 接下来我们就把亮色主题的背景改成默认的背景颜色.

为此我们就要想办法获取默认背景的颜色, 这里就牵扯到计算机中对颜色的表示了.

尽管在上面我们都是用单词表示颜色的, 似乎没有体现出"定量"的感觉, 但实际上, 对于计算机来说, 这些颜色都对应着特定的数值

![image-20251005112822097](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005112822097.png)

计算机中一种常用的颜色表示方法就是"RGB", 这三个字母分别表示光学的三原色, "red", "green", "blue", 这三种光的颜色就可以通过不同程度的混合, 搭配出其它各种各样的颜色. 我们显示屏上的像素小灯泡, 每一个都可以按照任意比例搭配三原色, 这样就能让显示屏显示出各种各样的颜色.

![image-20251005113640859](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005113640859.png)

在`RGB`中, 每个颜色的搭配长度用一个字节长度的数字表示, 即`0~255`, 当然用十六进制也是可以的, 即`0x00~0xFF`

现在我们已经知道了计算机的颜色表示方法, 就要应对另一个问题: 该如何把默认的背景颜色给取出来呢? 其实也很简单, 计算机中有一类专门的程序叫做取色器, 可以获取屏幕上具体某个点的颜色, 比如, PS上就有取色器. 不过呢, PS太重了, 对于我们这种并不从事于美术行业的人员来说, 可以使用一种更轻量的方法, 实际上, QQ截图就自带取色器.

唤醒QQ截图, 我们就可以看到这样的界面

![image-20251005131729749](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005131729749.png)

这里他就显示了一个十六位进制的色值, 并且按下C可复制色号

现在我们回到之前的程序上, 再次用QQ取色值

![image-20251005131915011](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005131915011.png)

这里我们就看到, 背景的默认颜色是#F0F0F0, 我们接下来改一下代码

![image-20251005132427011](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005132427011.png)

此时再次按下"亮色模式", 背景就是默认颜色

![image-20251005132518398](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005132518398.png)

最后要说的一点是, RGB其实上是计算机表示颜色的一种简化模型, 对于专门从事相关行业的人士来说, 可能还有包括色域, 色准, 色深之内的参数, 它们的显示器也需要特别配置, 以使得显示器更准确的显示颜色.

### QAbstractButton

前面我们曾经提到过, `Button`类控件都继承自`QAbstractButton`, `abstract`意为抽象的, 也就是说它是含有纯虚函数的抽象类. 无法被实例化, 如果将它继承则必须将其中的虚函数进行重写才行, 前面我们似乎说过`QAbstractButton`的抽象是语义层面, 而非语法层面的, 但在经过实际的测试之后, 发现以前的观点实际上是错的, 在这里我统一说明, `QAbstractButton`就是带有纯虚函数的抽象类


`QAbstractButton`的继承体系如下:

![image-20251005150726648](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005150726648.png)

正如前面我们说过的那样, Qt的各种控件都继承了`QWidget`, 所以前面我们说过的各种属性在下面的空间都是有效的. 因此下面如果用到相关的属性我们不会进一步说明. 而`QAbstractButton`向下又有四个子类, 我们重点会说明`QPushButton QCheckBox  QRadioButton`, 因为第四个`QToolButton`, 即工具按钮用的不多.

#### QPushButton

`QAbstractButton`中, 和`QPushButton`相关性较大的属性如下:

| 属性                 | 说明                                                         |
| -------------------- | ------------------------------------------------------------ |
| `text`               | 按钮显示的文本                                               |
| `icon`               | 按钮的图标样式                                               |
| `iconSize`           | 按钮图标的大小                                               |
| `shortcut`           | 按钮对应的快捷键                                             |
| `autoRepeat`         | 布尔类型, 描述长按按钮被视为按下一次还是多次, true视为按下多次, 反之亦然, 为方便起见, 我们引申枪战游戏的概念, 简化为是否可以"连发" |
| `autoRepeatDelay`    | 在``autoRepeat``为真的情况下, 描述刚开始按下后多长时间视为第二次按下 |
| `autoRepeatInterval` | 在``autoRepeat``为真的情况下, 描述自第二次按下开始再长按多长时间视为下一次按下 |

接下来, 我们就写一个项目, 为按钮增加图标, 

首先, 我们要有图片, 在这里, 我们就选用`doge`这张照片

![doge](https://md-wind.oss-cn-nanjing.aliyuncs.com/doge.jpg)

因为这张照片也很小, 所以我们还是使用`qrc`方案

![image-20251005155413026](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005155413026.png)

设计界面, 创建一个按钮

![image-20251005155711453](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005155711453.png)

在这里再顺便说一下与`qrc`有关的一个Qt bug, 那就是在处于别的文件的时候, 点击此处的`.qrc`文件并不会切换到`qrc`的那个界面

![image-20251005160012360](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005160012360.png)

但我们可以换一种方式进入界面, 那就是用此处的文件切换

![image-20251005160104620](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005160104620.png)

这样就可以进入界面了

![image-20251005160138806](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005160138806.png)

添加图标

![image-20251005160259156](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005160259156.png)

运行

![image-20251005160327830](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005160327830.png)

不过这里有些小, 那么我们可以用`IconSize`再改一下

![image-20251005160726240](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005160726240.png)

接下来, 我们把快捷键加进来

在前进, 我们曾经写过这样的一个项目: 通过四个按钮控制target的移动. 在这里, 我们仍旧是写一个类似的项目, 但将为四个方向键增加快捷键.

首先, 既然我们刚学了图标, 那么在这里我们也不使用文字表达按键的含义, 而是使用图标. 因为照片比较多了, 所以我们把上下左右的方向图标统一放到项目的一个子文件夹下.

```shell
PS D:\Repository\qt-lab\Qt6.5.3\QPushButtonShortCut> wsl ls -al image
total 48
drwxrwxrwx 1 wind wind  4096 Oct  5 17:18 .
drwxrwxrwx 1 wind wind  4096 Oct  5 17:18 ..
-rwxrwxrwx 1 wind wind 32544 Oct  5 15:48 doge.jpg
-rwxrwxrwx 1 wind wind  3416 Oct  5 17:10 down.png
-rwxrwxrwx 1 wind wind  3347 Oct  5 17:11 left.png
-rwxrwxrwx 1 wind wind  3204 Oct  5 17:10 right.png
-rwxrwxrwx 1 wind wind  3398 Oct  5 17:10 up.png
PS D:\Repository\qt-lab\Qt6.5.3\QPushButtonShortCut>
```

然后进入资源界面, 把这五个照片添加进来, 注意, 此时如果要访问它们, 也要带上`image`这个子文件

![image-20251005172151525](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005172151525.png)

![image-20251005172312670](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005172312670.png)

然后进入设计界面, 创建五个按钮

![image-20251005172749141](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005172749141.png)

![image-20251005172803278](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005172803278.png)

接下来, 我们为这些按钮添加图标

![image-20251005173209913](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005173209913.png)

关于图标大小的设置, 我们可以去设计界面的属性哪里查看按钮的尺寸

![image-20251005173306255](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005173306255.png)

![image-20251005173659521](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005173659521.png)

这里运行, 看一下效果

![image-20251005173741975](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005173741975.png)

接下来, 我们为方向键增加槽函数, 改变doge的位置, 之前我们应该是用move移动的, 既然如此, 在这里我们就使用`setGeometry`来移动

![image-20251005174318538](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005174318538.png)

现在, 我们运行鼠标点击按键已经可以移动了

![image-20251005174400517](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005174400517.png)

![image-20251005174415787](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005174415787.png)

接下来, 我们就要为按钮添加快捷键.

`setShortcut`的参数是`QKeySequence`, 即键序列, 为什么还有序列呢? 因为它也是支持组合键的.

![image-20251005174959240](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005174959240.png)

运行, 此时我们就可以用按键的方式控制doge的移动

![image-20251005175102542](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005175102542.png)

或者我们也可以使用Qt中对于键值的枚举常量.

![image-20251005175326930](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005175326930.png)

如果要表示组合键, 也就是与关系的话, 我们可以这样写

![image-20251005180108627](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005180108627.png)

有人可能会说, 与关系怎么用或操作符. 这是因为Qt内部对于这些键的编码是按照位图形式的, 像`QT::SHIFT`这样的键专门用于构成组合键, 它的低位都是零, 而像`Qt::Key_K`这样的键, 数值都比较小, 所以此处, `+`和`|`会达到相同的效果(当然, 他这里的语法提示不推荐+的写法)

![image-20251005180539596](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005180539596.png)

![image-20251005180554058](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005180554058.png)

![image-20251005180618261](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005180618261.png)

需要注意的事, 还存在`Qt::Key_Shift`这种键, 这种键不是起修饰作用的, 它的数值是在低位的, 所以无法起到修饰作用, 更直白地来说, 是只能单个用, 不能用在组合键里.

或者你也可以这样写, 但注意不要有空格

![image-20251005181256335](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005181256335.png)

如果你想表达或关系, 比如, 按下w和按下k效果相等, 那就需要用到`QShortcut`对象加上信号槽的写法

`QShortcut`是对快捷键的一种抽象, 它可以起到一种内存级别键盘控件的效果, 当某个被按下时, 对应的`QShortcut`就会发出激活信号, 从而触发按钮的按下槽函数, 它可以说是一种虚拟控件, 所以需要挂载到对象树上.

![image-20251005183446396](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005183446396.png)

不能再调一次`setShortcut`, 那样相当于覆盖.

除此之外, 在上面程序的运行中, 我们还可以体会到键盘上的按键默认就是可以连续按下的, 也就是`autoRepeat`默认为`true`: 一直按着键盘, 就可以一直移动, 但鼠标一直按着则不行. 也就是键盘可以连发, 鼠标不行.

如果我们想让鼠标也支持连发, 直接进行设置即可

![image-20251005184236253](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251005184236253.png)

#### QRadioButton

"radio"在此处表示的意思是"单选", 而非收音机. 至于为什么用"radio"这个单词, 是因为早期的收音机上有三个用来选择频段的三个机械按钮(AF, FM, 短波), 这三个按钮的特性就是只能按下一个, 原先被按下的按钮会自动弹起, 而这正符合单选按钮的逻辑.

`QAbstractButton`中和`QRadioButton`关系较大的属性如下:

| 属性             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| `checkable`      | 是否能选中                                                   |
| `checked`        | 在`checkabel`为`true`的前提下, 表示是否被选中                |
| `autoExclusive ` | 是否排他, 选中⼀个按钮之后是否会取消其他按钮的选中.  对于`QRadioButton`来说, 默认就是排他的 |

下面我们就写一个调查问卷, 询问你是否愿意自愿加班.

进入设计界面

![image-20251006112925313](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006112925313.png)

然后我们再加点互动语吧

![image-20251006113626899](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006113626899.png)

运行, 我们看到, 只能选一个按钮, 选了这个, 另外一个就会自动取消, 也就是具有排他的效果

![image-20251006113729297](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006113729297.png)

![image-20251006113740140](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006113740140.png)

![image-20251006113750820](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006113750820.png)

我们可以为这个单选设置一个默认的选项

![image-20251006114445487](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006114445487.png)

这样就不用我们的员工再手点了, 这不省事吗?

接下来, 我们再禁用"不愿意"这个选项, 这样就可以更省事了.

![image-20251006114806060](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006114806060.png)

这样, 我们就选择不了"不愿意"按钮

![image-20251006114834587](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006114834587.png)

不过稍微有些问题, 它的按下信号还是被触发了, 因此有标签的文本互动.

因此, 我们使用`QWidget`中的`enable`或者`disable`属性都行.

![image-20251006115419576](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006115419576.png)

----------

在之前, 我们曾说, 有两个`QAbstractButton`中的信号函数在`QPushButton`里说不了, 那么, 我们就在这里演示一下效果

![image-20251006120104271](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006120104271.png)

我们还是新建一个项目, 进入设计界面, 拖入四个`QRadioButton`, 分别对应`clicked(bool), pressed(), released(), toggled(bool)`

![image-20251006120635433](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006120635433.png)

![image-20251006120759117](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006120759117.png)

带参数的`clicked`, 表示按下后是否被选中, 你可能会问按下后那不铁定被选中吗? 那不一定, 比如像之前那样, `checkable`是`false`.  `pressed`则是按下时信号激活, `released`则是松开后信号激活.`toggled`则是状态切换, 也就是选到没选中, 或者没选中到选中时触发, 参数依旧是它有没有选中.

![image-20251006121509426](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006121509426.png)

我们看到, 点下多少1, 那就打印多少次

![image-20251006121555996](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006121555996.png)

2, 没松下就打印

![image-20251006121637591](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006121637591.png)

3 松下才会打印

![image-20251006121714871](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006121714871.png)

![image-20251006121729689](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006121729689.png)

4 从没选中到选中

![image-20251006121831842](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006121831842.png)

从选中到没选中

![image-20251006121900179](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006121900179.png)

---

接下来我们再写一个菜单, 我们知道肯德基它们有套餐的概念, 每个套餐又分为三个组, 分别是, 汉堡, 小食, 饮料. 组与组之间相互独立, 组内的各个选项互相排他.

![image-20251006123619036](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006123619036.png)

运行, 我们发现选倒是能选, 但它们似乎都被视为同一组

![image-20251006123714813](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006123714813.png)

![image-20251006123726752](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006123726752.png)

因此我们就需要为这些`QRadioButton`分组, 这里就要引入`QButtonGroup`这个工具对象, 对不同的按钮进行分组

![image-20251006124210315](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006124210315.png)

此处, 我们就把前三个按钮分到了第一组里

![image-20251006124240011](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006124240011.png)

当然, 设计界面也可以分组, 矩形选中, 右键, 新建按钮组

![image-20251006124411584](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006124411584.png)

后面两个我们就用设计界面的方式, 然后, 运行

![image-20251006124526345](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006124526345.png)

#### QCheckButton

同样是选择按钮, 相比`QRadioButton`, `QCheckButton`不再具有默认的排他性, 也就是说, 它是~~符玄~~复选按钮. 

`QCheckButton`和`QAbstractButton`最相关的属性也是`checkable`和`checked`, 尽管, `QCheckButton`也有独有的属性`tristate`, 用来实现"三态复选框", 但用的很少, 这里不会提及.

接下来我们直接上代码

![image-20251006132239458](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006132239458.png)

多选之后, 按下确认, 标签将会总结安排

![image-20251006134012561](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006134012561.png)

运行

![image-20251006134052436](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006134052436.png)

我们发现, 和我们想的不太一样, 坏了, 真要找bug了.

其实问题也很简单, 我们设计界面的标签太小了, 后面的字没显示出来

![image-20251006134215790](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006134215790.png)

调大一些就行了

![image-20251006134236213](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006134236213.png)

我们看到, 现在就正常了

![image-20251006134307958](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006134307958.png)

### QDisplay

下面我们要介绍 Qt 的显示控件。与按钮不同，显示控件的继承体系并不统一。Qt 在设计时，并没有为它们提供一个类似 `QAbstractButton` 的总抽象类，而是根据不同功能领域进行分类抽象。这么做的原因在于，显示控件的种类跨度很大，难以用单一的父类来涵盖。这里我使用 **`QDisplay`** 作为标题，并不是要说明 Qt 中真的存在这样一个类，而是为了方便归纳，将这些显示控件统一放在一个小节中讨论。在后续的介绍里，我们也会更多地从控件本身的功能出发，而不是强调它们的继承关系。

#### QLabel

我们首先介绍我们已经用到很多次, 并且将来也会主要用的`QLabel`. 可以用来显示文本和图片, 其具体的核心属性如下:

- `text`
  顾名思义, 用于描述`QLabel`显示的文本内容
- `textFormat`
  描述文本的格式, 有四个枚举值可供选择 1) 纯文本`Qt::PlainText` 2) 富文本`Qt::RichText` 3) markdown`Qt::MarkdownText` 4) 自适应`Qt::AutoText`. 
  纯文本就是普通的文本, 富文本则可以通过支持诸如html标签之类的东西, 从而使文本变得更加丰富, word文本的格式就是富文本的一种, markdown则是程序员群体常用的一种文本格式, 笔者超过九成的文档都是markdown写的, 也包括这篇, 相比富文本, markdown更加轻量, 并且对于程序开发也很受用, 自动, 那就是自然是让`QLabel`自己根据文本内容进行猜测
- `pixmap`
  指`QLabel`内部的图片
- `scaledContents`
  布尔值, 主要是标签有图片之后再使用, 因为文本没什么好拉伸的, `true`表示让图片自动拉伸填充标签. `false`则表示不会.
- `alignment`
  表示对齐方式. 可以设置水平和垂直方向如何对齐. 对于大多数文字来说, 似乎使用的都是左对齐, 从上往下排布, 当然文字上的情况下, 你也可以让它水平竖直居中.
- `wordWrap`
  布尔值, 描述是否让文本自动换行. 有时, `QLabel`的文本很长, 在加上`QLabel`没有像`QTextEdit`那样有滚动条, 所以就会造成文本的后半部分显示不出来, 此时将该属性设置为`true`, 便能使得其中的文本自动换行.
- `indent`
  设置文本缩进, 水平和垂直方向都生效
- `margin` 
  用于设置内部文本与边框之间的间距, 上下左右都会生效, 这一点, 它不同于`indent`, 因为`indent`最多只有两个方向有效(具体哪两个方向取决于`alignment`对齐方式)
- `openExternalLinks`
  当文本中含有`url`的时候, 描述用户点击该链接允不允许跳转到相应的网络资源上.
- `buddy`
  `QLabel`特有的属性, 可以为`QLabel`关联一个伙伴, 比如, 关联一个`QCheckBox`, 此时, 点击`QLabel`就相当于点击了``QCheckBox`.

------

下面的项目用于展示`textFormat`属性

我们首先在设计界面创建三个`QLabel`

![image-20251006154215865](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006154215865.png)

![image-20251006154704419](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006154704419.png)

运行, 因为这里我们并没有使用各个语言的特有内容, 所以看起来一样

![image-20251006154839754](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006154839754.png)

这里, 我们使用富文本的`<b></b>`标签, 表示加粗字体

![image-20251006155021784](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006155021784.png)

我们就可以看到, `Plain`将其视为正常的文本内容, 而富文本则渲染出对应的效果

同样的`~~ ~~`表示删除线,

![image-20251006155258727](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006155258727.png)

----

下面, 我们使用`QLabel`显示图片

首先, 我们在设计界面创建`QLabel`

![image-20251006163520987](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006163520987.png)

然后我们引入资源文件

![image-20251006164621070](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006164621070.png)

我们打算让整个标签覆盖整个窗口, 然后让照片平铺在标签上

![image-20251006165326815](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006165326815.png)

![image-20251006165340242](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006165340242.png)

我们看到, 比例不是特别对, 所以我们可以手动调整一下窗口的大小

但此时我们就发现了一个问题 

![image-20251006165437276](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006165437276.png)

窗口大小被用户手动改变后, `QLabel`并没有自适应.

这也好理解, 因为我们是在构造函数里, 设置`QLabel`的大小, 而在之后, 它的大小也会不变, 即使窗口本身的大小又人为地调整.

所以接下来我们要做的, 就是想办法, 让`QLabel`能够跟着窗口自已改变大小

此处，我们就能够引出 Qt 用来描述用户交互行为的另一个概念——事件。用户与界面的交互大致可以分为两类：一类是对控件状态的改变，属于**状态性的行为**；另一类则是一种持续发生的改变，属于**过程性的行为**。在上述操作中，当我们通过拖拽方式调整窗口大小时，就会触发 `resize` 事件。需要注意的是，这个事件在拖拽过程中会持续不断地发生，而并非只触发一次。

下面, 我们就将通过重写`QWidget`的`resizeEvent`虚函数来展现其中的具体过程.

![image-20251006170944309](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006170944309.png)

![image-20251006170827865](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006170827865.png)

这里的形参`event`就描述了触发这一事件时, 窗口尺寸的数据

再次运行, 我们就能看到它输出了一个初始尺寸

![image-20251006171116159](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006171116159.png)

现在用鼠标拖拽窗口

然后我们就看到它连续触发了很多次

![image-20251006171226757](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006171226757.png)

所以只要我们在这里也顺带改变一下标签的尺寸就行

![image-20251006171649595](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006171649595.png)

运行

![image-20251006171705656](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006171705656.png)

改变窗口尺寸

![image-20251006171736634](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251006171736634.png)

----

接下来我们看有关文本对齐, 自动换行, 缩进, 边距的属性.

设计界面拖入一个标签, 我们看到, 标签在默认情况下没有显现边框, 所以不太好观察

![image-20251007102722536](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007102722536.png)

为此, 我们可以选中标签, 在右下角的属性界面去找`shape`, 也就是形状属性. 并且我们在其中也能看到`QLabel`的继承体系

![image-20251007102927825](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007102927825.png)

把`frameShape`改成`box`效果

![image-20251007103119765](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007103119765.png)

![image-20251007103342373](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007103342373.png)

接下来我们以此为蓝本, 复制出其它三个

![image-20251007103511230](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007103511230.png)

![image-20251007104537049](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007104537049.png)

与对齐方向有关的枚举都是以比特位编码的形式取值的, 所以使用按位或就可以将它们都设置上去, 这在Linux那边我们也见到过

![image-20251007104711091](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007104711091.png)

![image-20251007105051351](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007105051351.png)

![image-20251007105104998](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007105104998.png)

![image-20251007105121804](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007105121804.png)

![image-20251007105333509](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007105333509.png)

![image-20251007105432139](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007105432139.png)

接下来我们看自动换行, 对于一个长文本来说, 标签可能显示不全

```cpp
 // 设置自动换行
    ui->label_2->setText(
        "星照夜, 夜映星; 星在夜中看光明. 光照夜, 夜藏光, 光与夜里梦相生. "
        "梦生影, 影化形, 形在光中又化影. 影照星, 星入梦, 梦回夜色生无穷. "
        "夜里有光, 光中有夜, 星在光里呼吸着夜; 夜在星下凝望着光, 一息一照, 一照一长. "
        "长生不灭, 灭而复生, 生在光中, 灭在夜中; 星在夜里照夜的星, 夜在星中藏星的梦. "
        "光行夜海, 夜载光舟, 星是灯, 梦是流; 一明一暗, 一来一往, 万象生于这呼吸的荡漾."
        );
```

![image-20251007111944248](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007111944248.png)

此时我们就可以设置自动换行

![image-20251007112256738](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007112256738.png)

缩进

![image-20251007112643825](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007112643825.png)

![image-20251007113237970](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007113237970.png)

不过对于Qt的缩进有些是要注意的, 我们挑一个更长的文本

```cpp
 // 设置缩进
    ui->label_3->setText(
        "吾闻二世少子也，不当立，当立者乃公子扶苏。"
        "扶苏以数谏故，上使外将兵。"
        "今或闻无罪，二世杀之。百姓多闻其贤，未知其死也。"
        "项燕为楚将，数有功，爱士卒，楚人怜之。"
        "或以为死，或以为亡。"
        "今诚以吾众诈自称公子扶苏﹑项燕，为天下唱，宜多应者。"
        );
    ui->label_3->setWordWrap(true);
    ui->label_3->setIndent(50);
```

![image-20251007113754221](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007113754221.png)

我们发现, Qt的缩进并不是我们以为的首行缩进, 是所有行都缩进, 这与其它的图形化界面技术, 比如网页前端的CSS不太相同, 它们是首行缩进.

接下来是边距

```cpp
//设置边距
    ui->label_4->setText(
        "吾闻二世少子也，不当立，当立者乃公子扶苏。"
        "扶苏以数谏故，上使外将兵。"
        "今或闻无罪，二世杀之。百姓多闻其贤，未知其死也。"
        "项燕为楚将，数有功，爱士卒，楚人怜之。"
        "或以为死，或以为亡。"
        "今诚以吾众诈自称公子扶苏﹑项燕，为天下唱，宜多应者。"
        );
    ui->label_4->setWordWrap(true);
    ui->label_4->setMargin(50);
```

边距的特点就是它是四个方向都生效的, 缩进只有一个方向

![image-20251007115129333](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007115129333.png)

这里我们就能看到, 整个文本看上去似乎都被边距吞了.

这里我们再缩小一下

![image-20251007115318450](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007115318450.png)

---

在最后, 我们演示一下`QLabel`的伙伴功能. 这个功能主要是配合单选框或者复选框给用户更多的交互方式. 直接用语言描述或许有些苍白, 接下来, 我们就直接通过一个项目来演示.

我们创建两个`QRadioButton`和与之对应的`QLabel`

![image-20251007133008075](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007133008075.png)

你可能疑惑为什么标签内的文本要这样写, 因为这是让伙伴发挥作用的要求.

接下来, 我们去代码那边, 建立伙伴关系

![image-20251007133246259](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007133246259.png)

运行后, 我们发现点击标签不会有任何反应, 并且文本中的取地址符`&`也消失了

![image-20251007133405910](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007133405910.png)

但是如果我们使用`ALT A`或者`ALT B`选择对应的单选框

![image-20251007133515716](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007133515716.png)

这是一种弱快捷键, 必须是`ALT`作为修饰键, 按下对应的快捷键, 就能选择对应的单选或者复选按钮

我们`Creator`上面的那些选项用的也是这个逻辑

![image-20251007133754862](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007133754862.png)

你按下`atl f`也会打开文件选项

#### QLCDNumber

`QLCDNumber`是最早期的显示控件之一, 在它身上有一些历史上的痕迹.

首先, 就它的样子来说, 是一种写实风, 就是我们以前可能用到的LCD数字显示屏, 就像实体计算器上的显示屏

![3118_0_l](https://md-wind.oss-cn-nanjing.aliyuncs.com/3118_0_l.jpg)

核心属性如下

- `intValue `
  表示`QLCDNumber`要显示的整数
- `value`
  表示`QLCDNumber`要显示的浮点数
  这两个`value`不是完全独立的, 如果设置`value`是`1.5`, 那么去`intVal`那里读出来则是`2`, 并且这两个`value`的写接口, 也不是`set`作为前缀, 而是都使用`display`来写. 至于为什么这样做, 可能是太早了, 当时随口叫了一个意思很明确的意思, 后来叫久了, 改不回来了.
- `digitCount`
  表示显示的数位.
- `mode`
  显示数字的形式, `QLCDNumber:Dec`十进制, `QLCDNumber:Hex`十六进制, `QLCDNumber:Bin`二进制, `QLCDNumber:Oct`八进制, 这个枚举的命名域和现代Qt也不太一样, 要注意, 小数点后的内容只有十进制才能显示
- `segmentStyle`
  显示风格. `QLCDNumber::Flat`, 数字呈现在一个平坦的表面上, `QLCDNumber::Outline`, 数字有清晰的轮廓和阴影效果, `QLCDNumber::Filled`, 数字被填充颜色, 并且颜色与背景区分开来.
- `smallDecimalPoint `
  使用更小的小数点

下面我们就使用`QLCDNumber`写一个倒计时程序

首先设计界面拖入一个`QLCDNumber`

![image-20251007152521330](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007152521330.png)

在右下角可以看到与之有关的各类属性

![image-20251007152610231](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007152610231.png)

风格改成`Outline`就是这样

![image-20251007152708584](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007152708584.png)

`flat`

![image-20251007152747963](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007152747963.png)

最后还是切换回最开始的`filled`

![image-20251007153159874](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007153159874.png)

![image-20251007153144052](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007153144052.png)

如果要实现每一秒种减一的效果, 则需要使用"定时器". 这种周期性执行某个逻辑的需求在开发中其实还是很常见的, 但C++标准库中并没有定时器, 不过Boost里面有定时器, Qt作为侧重于开发的一个框架, 也有定时器, 并且定时器也是高度融合到信号槽的机制中的. Qt中的定时器叫做`QTimer`, 在`start`后, 每过指定的时间, `QTimer`就会发出`timeout`信号, 利用这个信号, 就可以调用某个槽函数.

![image-20251007160832101](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007160832101.png)

![image-20251007160843930](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007160843930.png)

<video src="https://md-wind.oss-cn-nanjing.aliyuncs.com/2025-10-07%2015-50-00.mp4"></video>

-------

可能有人会问, 能不能通过其它方式达到相同的效果呢? 那在这里我们就直接写代码, 看看相应的现象.

这次我们就在设计界面里赋初值

![image-20251007161324439](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007161324439.png)

第一种方案, 既然和时间有关, 那能不能直接调用`sleep`呢? 当然, 由于我们使用的编译器是MinGW, 它用不了Linux的系统接口`sleep`, Windows系统接口也就是`Sleep`,  尽管能用, 但既然Qt是跨平台的, 那我们就用C++11的`sleep_for`

![image-20251007162855897](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007162855897.png)

此时我们运行, 就会发现, 构建成功后窗口迟迟不出现, 直到过了十秒后, 才弹出一个已经归零的倒计时

![image-20251007163013278](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007163013278.png)

这是因为, 这段代码是在构造函数里运行的, 但构造函数只是把程序的各个内存级别的数据初始化, 真正的弹窗弹出是`show`执行之后,之后便一直在`exec`里进行主循环.

![image-20251007163625210](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007163625210.png)

并且, `show`和`exec`也不是虚函数, 你也没办法拿它们做文章, 因为它们内部有很多敏感操作, 为了程序安全, 是不允许直接改的.

于是就有了第二种方案, 这也是我们重点想说的, 我们再引入一个线程, 这样的话, 就不会把主线程给卡住, 他就能顺利地把`show`执行完毕.

![image-20251007164701535](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007164701535.png)

一运行, 就运行出错了

![image-20251007164729669](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007164729669.png)为什么会出现进程终止这种情况呢? 因为它内部隐藏了很多的状态, 为了保护它们的线程安全, Qt禁止其它线程对于界面的直接修改, 而在上面, 我们做的正是做了Qt禁止的事.

#### QProgressBar

`ProgressBar`就是我们常见的进度条-- 当进程正在进行耗时操作时, 就给用户一个进度条, 意在提醒用户, 我没有卡, 正在做事, 你不要急. 让用户省点心.

核心属性有

- `minimum`
  描述进度条最小值, 一般就是0
- `maximum`
  描述进度条最大值, 一般就是100
- `value`
  描述进度条当前显示的数值
- `alignment`
  描述文本在进度条中的对齐方式
  `Qt::AlignLeft`左对齐, `Qt::AlignRight`右对齐, `Qt::AlignCenter`居中对齐, `Qt::AlignJustify`两端对齐
- `textVisible `
  进度条的数字文本是否可见
- `orientation `
  进度条的方向是水平还是垂直
- `invertAppearance `
  进度条增长的方向是正向的还是反向的(从右往左)
- `textDirection`
  文本的朝向
- `format `
  展示的数字格式
  `%p`表示进度的百分比, `%v`表示进度的数值, `%m`表示剩余的时间, 单位毫秒, `%t`, 表示总时间

进度条的代码逻辑一般是, 设置一个定时器, 每隔一段时间就发信号进入槽函数, 然后在槽函数里计算一下当前工作的进度, 比如如果是把文件读到内存里, 那就看看已经读了多少, 又还剩下多少, 计算一下百分比, 再重新设置一下`value`. 那在这里我们并没有实际的应用场景, 所以我们在槽函数里面就直接加一了.

![image-20251007180903758](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007180903758.png)

![image-20251007183749007](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007183749007.png)

运行

<video src="https://md-wind.oss-cn-nanjing.aliyuncs.com/2025-10-07%2018-38-59.mp4"></video>

我们看到, 设计界面和实际运行的效果并不一致, 很明显的一点就是, 设计界面使用的颜色是蓝绿色, 而实际运行使用的则是绿色.

出现这种情况的原因是因为, 在默认情况下, 也就是你没有设置`styleSheet`的前提下, Qt对于控件样式的绘制依赖于`QWidget`的另一个属性, 叫做`style`, 你也许说, 不就缺了一个`sheet`吗? 有什么区别, 但实际上, 区别是很大的, `sheet`是基于C++语言本身的样式绘制引擎,叫做`QStyle`, 而`styleSheet`我们在前面也说过, 它是基于`QSS`的绘制引擎, 它们两个的技术路线是完全不同的. 

`QStyle`的样式是建议性的, 实际由平台自己决定, `QSS`则是强制性的, 平台必须照做. 所以尽管`QStyle`的颜色属性使用的确实是蓝绿色, 但实际上操作系统最终使用了绿色(难怪我平时见到的进度条从来都是绿色). 记住这里的建议性和强制性, 马上我们还会遇到.

接下来我们就使用QSS, 也就是样式表的形式, 修改进图条的样式, 为了方便起见, 这里我们就单纯改一下样式

进入设计界面, 我们直接进入样式列表的编辑界面

![image-20251007193735824](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007193735824.png)

因为进度条实际上是由很多更小的组件组成的, 所以在进行样式设置时, 就需要指定到底是给谁进行设置, `QProgressBar::chunk`中的`chunk`指的就是进度条的主体, 也就是那个色块, 把它的背景设置成`#00CDDA`.

设置过后我们感觉设计界面的进度条怪怪的, 我们不管他

![image-20251007193854991](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007193854991.png)

运行

![image-20251007193915789](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007193915789.png)

我们发现这个运行结果其实也有些不太对.

为什么会出现这种情况呢? 还是因为我们之前说过的, `QSS`的优先级别比`QStyle`要高, 所以你只要使用了`QSS`, 它就会只使用`QSS`的内容, 相当于把原来`QStyle`的属性给丢弃掉了, 就像我安装火绒之后, Windows安全中心就什么都不管那种. 在这里解决的方案也很简单, 把QSS给补全就行了.

```CSS
QProgressBar {
    background-color: #E6E6E6;  /*进度条背景*/
    text-align: center;         /* 文字局中 */
    color: #000000;             /* 文字颜色为黑 */
}

QProgressBar::chunk {
    background-color: #00CDDA;  /*进度条色块是蓝绿色*/
    color: #FFFFFF;             /* 高亮文字为白色 */
}
```

![image-20251007195828346](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007195828346.png)

这里我们可能并没有完全补齐, 但在视觉效果差不多了.

不过QSS本身似乎不支持把文字放到边框的右边, 不过如果你真的很想要的话, 大不了可以把字体给隐藏, 然后右边放一个标签, 我还看到一些其他方案, 但这些方案都比较麻烦, 我自己也没有亲自试试可不可行, 所以就不说了.

-----

在最初的进度条版本中, 不知你是否看到一个细节, 那就是我的头文件都是放在`.cpp`里的

![image-20251007200656643](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007200656643.png)

(新加的内容是我打印`QStyle`属性的, 在这里不用管)

但是, 我们在头文件那里命名定义了一个`QTimer*`, 但编译却没有出错

![image-20251007200834285](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251007200834285.png)

这是为什么呢? 其实这里就牵扯到Qt的一个小特性.

在以前的Qt中有一个很特殊的头文件, 它里面主要写的是Qt中各种类的前置声明, 而这个头文件又会被其他头文件包含, 最终被我们包含. 因为有前置声明, 所以你用一下它们的指针是完全可以的, 所以头文件这里直接用是可以的 , 但实际使用那就需要真正的头文件了, 所以我们在`.cpp`这里还是要包含.

你可能会疑惑, Qt为什么会这样设计? 其实这和Qt本身并没有关系, 而和C++这个语言本身有关. C++有一个弊病, 那就是相比其他语言来说, 它的编译速度很慢, 为什么慢呢? 主要就在于头文件的文本展开和编译, 别的语言为什么比较快?那是因为别的语言有个叫模块的东西, 模块就相当于已经把头文件提前编译了一下, 所以最后编译的时候自然就很快, Qt这种前置声明的做法就是一种缓兵之计, 它想尽可能减轻头文件嵌套包含的复杂程度, 写了前置声明之后, 那就能稍微减少一些.

你可能会问, 那这个头文件在哪里, 我想看看, 那我在这里就告诉你, 看不了, 因为即使是我这个电脑上较老的那个Qt5.14.2已经不使用这个技术路线了, 更别说是这个Qt6.

在C++20, 引入了类似于其他语言模块的机制, 想要从源头上解决编译速度慢的问题, Qt也进行了适配, 所以现在Qt用的技术路线都是模块. 当然, 为了兼容以前的C++, `include`仍旧是可以使用的.

实际工作中, 我们也不用操心编译慢的问题, 对于资本更为雄厚的互联网公司来说, 它们会专门建立一个编译集群, 这些集群里有很多高性能的服务器, 编译的时候, 把代码提交上去, 然后服务器集群分布编译, 这样速度就会快很多.

#### QCalendarWidget

`Calendar  `就是日历. 一般来说, 日历常被用来用来进行日期选择, 这样最起码就不用考虑用户手动输日期时输错的处理了.

核心属性如下:

- `selectDate`
  选中的日期
- `minimumDate`
  最小日期, 一般选默认的就行
- `maximumDate`
  最大日期, 一般不用改
- `firstDayOfWeek`
  每周第一天是周几
- `gridVisible `
  是否显示表格的边框
- `selectionMode`
  是否允许选择日期
- `navigationBarVisible`
  日历上方标题是否显示
- `horizontalHeaderFormat`
  日历上方标题显示的日期格式
- `verticalHeaderFormat `
  日历第一列显示的内容格式
- `dateEditEnabled`
  是否允许⽇期被编辑

有关的重要信号包括

- `selectionChanged() `
  选中日期发生改变时发出
- `activated(const QDate&)`
  双击日期或者按下回车时发出, 参数表示选中的日期
- `currentPageChanged(int,  int) `
  当年份⽉份改变时发出，形参表⽰改变后的新年份和⽉份 

下面我们就直接新建项目

拖入后, 直接转到槽

![image-20251008105311688](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008105311688.png)

运行, 此时选择一个日期, 就会输出相应内容

![image-20251008105623626](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008105623626.png)

`QDate`里面还有个`to_string`方法

![image-20251008110000983](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008110000983.png)

### QInput

#### QLineEdit

`QLineEdit`用来表示单行输入框, 可以输入一段文本, 但是不能换行

核心属性如下

- `text`
  输入框中的文本, 可以通过代码或者用户输入来修改
- `inputMask`
  描述一个规则, 用于约束输入内容
- `maxLength`
  最大长度
- `frame`
  是否添加边框
- `echoMode`
  回显方式
  `QLineEdit::Normal` 输入什么显示什么
  `QLineEdit::Password`输入的实际内容将会被隐藏, 用以保护隐私信息
  `QLineEdit::NoEcho`不回显
- `cursorPosition`
  光标位置
- `alignment `
  文字对齐方式, 分为水平和垂直两个方向
- `dragEnabled`
  是否允许以文字拖拽的形式输入内容
- `readOnly `
  文本内容是否是只读的
- `placeHolderText `
  输入框内容为空时, 显示的提示文本
- `clearButtonEnabled `
  提供一个按钮, 能够清空输入内容

核心信号有

- `void cursorPositionChanged(int old, int new)`
  鼠标移动时发出信号, 参数表示新旧位置

- `void editingFinished()`
  当按返回或者回车时, 或者行编辑失去焦点时, 发出此信号

- `void returnPressed()`
  当返回或回⻋键按下时发出此信号, 如果设置了验证器, 则必须验证通过, 才能触发

- `void selectionChanged()`
  当选中的文本发生改变时, 触犯该信号

- `void textChanged(const  QString& text)`
  当`QLineEdit`的文本内容改变时, 触发该信号, 通过代码方式修改也会触发

- `void textEdited  `
  当`QLineEdit`的文本内容改变时, 触发该信号, 通过代码方式修改不会触发

-------

下面, 我们就写一个表单, 让用户输入个人信息

![image-20251008135802437](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008135802437.png)

![image-20251008140028390](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008140028390.png)

一旦输入内容, 占位文本就会消失

![image-20251008140103059](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008140103059.png)

打开清除按钮后, 点击右侧`×`号即可清除文本

![image-20251008140311140](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008140311140.png)

![image-20251008140747270](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008140747270.png)

![image-20251008141144252](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008141144252.png)

我们知道手机号码是有固定格式的, 在这里我们就格式化约束一下

![image-20251008141357346](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008141357346.png)

此处的零表示只能输入数字吗也就是说这个输入框只能输入11个数字, 而且在显示上将会按照344的划分用`-`隔开

![image-20251008141607746](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008141607746.png)

`inptMask`只能进行简单校验, 等会儿, 我们会通过正则表达式, 来进行更严格更复杂的校验.

最后在确认按钮, 我们收集输入的信息, 将其打包, 输出

![image-20251008142859148](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008142859148.png)

![image-20251008142843813](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008142843813.png)

当然, 真实情况下, 会打包输出到网络, 然后到服务器.

-----

接下来, 我们使用正则表达式, 对输入的内容进行验证. 其实我们在之前, 已经遇到过很多次正则表达式了, 这是计算机中的一个通用概念, 用于定量描述目标字符串的特征.

正则表达式的具体语法比较复杂, 我们也不会特意去记, 确实难记, 一般都是需要用到的时候查查表, 比如[此处](https://learn.microsoft.com/zh-cn/previous-versions/visualstudio/visual-studio-2008/ae5bf541(v=vs.90))就是微软提供的正则表达式语法表. 然后自己写出来之后再找个[测试器](https://regextester.buyaocha.com/)测试一下

![image-20251008144102303](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008144102303.png)

对于手机号码来说, 它有如下的两个特征: 1) 由11个数字构成 2) 开头是一, 于是我们就可以用正则表达式描述给计算机.

我们新创建一个项目, 分别含有一个`QLineEdit`和`QPushButton`, 默认情况下, 确认按钮将不可使用, 直到, 输入内容符合正则表达式约束内容.

此处直接通过设计界面属性界面规定按钮默认情况下无法使用

![image-20251008150150798](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008150150798.png)

这里我们为`LineEdit`注册了一个验证器, 但具体这个验证器怎么用, 则需要依靠槽函数

![image-20251008151653203](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008151653203.png)

当文本改变时, 进行验证

![image-20251008151756045](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008151756045.png)

使用`textChanged`和`textEdited`都差不多, 这里我们选择后者

验证器对象`QRegularExpressionValidator`含有方法`State validate(QString&, int&)`用于进行验证, 注意`QString&`是普通引用, `int&`表示出错范围, 返回值`State`是个枚举类型, 表示检验的三种结果, 

| 返回值                     | 枚举值 | 含义                     | 举例说明                                                     |
| -------------------------- | ------ | ------------------------ | ------------------------------------------------------------ |
| `QValidator::Invalid`      | 0      | 明显无效，完全不符合要求 | 输入字母 “a” 时，手机号验证器会认为无效, 因为开头必须是一, 阻止进一步输入 |
| `QValidator::Intermediate` | 1      | 目前有效, 但不完整       | 输入 “13” 时，虽然还不是完整手机号，但并未出错, 可以继续让用户输入 |
| `QValidator::Acceptable`   | 2      | 完全有效，符合规则       | 输入 “13812345678” 时，验证通过                              |

在此处, 电话号码应该完整并且不出错, 即完全有效, 才使能按钮(使能的意思就是enable为true)

![image-20251008154018078](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008154018078.png)

运行, 输入11个数字就不能继续输入, 并且也输入不了其它字符, 第一个数字也只能输入`1`

在实际工作中, 我们也一般不亲自写正则表达式, 而是直接去网上搜一份, 然后复制过来, 当然你要能看懂那个正则表达式是什么意思.

---------

接下来, 我们写一个很常用的功能, 密码的双重确认输入框.

在我们注册账号设置密码时, 为确保, 没有无意中输错字符, 一般会设置一个确认密码, 当密码与确认密码一致后才可进行下一步.

这里有三个组件, 两个输入框, 一个标签, 输入框输入密码, 标签输出提示

![image-20251008155044405](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008155044405.png)

![image-20251008161322495](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008161322495.png)

`textEdited`实际上有参数, 但我们这里槽函数其实并不用, 所以实现干脆不带参

![image-20251008161420463](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008161420463.png)

![image-20251008161526798](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008161526798.png)

![image-20251008161539195](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008161539195.png)

-----------

最后, 我们还是讲密码, 我们为密码框增加一个效果: 我们给密码框旁边加个复选框, 勾选就可以显示密码的实际内容

理论上, 这其实并不难, 勾选之后槽函数改一下属性, 不过因为很常用, 所以我们还是写一下.

![image-20251008162636886](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008162636886.png)

这里我们选择`toggled`信号函数, 这是因为如果不选我们还要把风格调回隐藏模式, 所以状态变化更合适

![image-20251008162914464](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008162914464.png)

![image-20251008163149094](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008163149094.png)

运行

![image-20251008163128271](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008163128271.png)

![image-20251008163137622](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008163137622.png)

#### QTextEdit

`QTextEdit`表示多行输入框, 也是一个富文本&markdown编辑器, 并且能在内容超出范围后自动提供滚动条.

Qt中的多行输入有两种, `QTextEdit`和`QPlainText`, 它们的区别就是, `QPlainText`只支持纯文本, 但对于`QText`来说, 纯文本, 富文本, markdown都是支持的.其它都差不多.

核心属性

- `markdown`
  有`setMakrdown`, 可以将代码形式的输入字符串解释为`markdown`格式

- `html`
  有`setHtml`, 可以将代码形式的输入字符串解释为`html`格式

- `placeHolderText`
  占位文本

- `readOnly`
  不可编辑, 只读

- `undoRedoEnable`
  是否开启`undo`(`CTRL Z`撤销)`redo`(`CYRL Y`恢复)功能

- `autoFormating`
  开启自动格式化

- `tabstopWidth `

  `tab`键占据几个空格

- `overwriteMode`
  是否开启覆写模式
  计算机的文本处理器有两种模式, 一是我们平常默认使用的插入模式, 在字符串中输入字符会插入字符, 二是覆写模式, 此时在字符串中输入字符会顶替掉后面的字符, vim的`R`模式就是这样, 键盘上的`INS`可以开启覆写模式, 不过某些软件可能已经不支持覆写. 

- `acceptRichText `
  是否接收富文本内容

- `verticalScrollBarPolicy `
  垂直方向滚动条的出现策略
  `Qt::ScrollBarAsNeeded`默认行为, 文本超出输入框自动出现滚动条
  `Qt::ScrollBarAlwaysOff`总是关闭滚动条
  `Qt::ScrollBarAlwaysOn`总是显示滚动条

核心信号

- `textChanged()`
  文本内容改变时触发
- `selectionChanged()  `
  选中范围改变时触发
- `cursorPositionChanged()`
  光标移动时触发
- `undoAvailable(bool)`
  进行`undo`操作时触发, 参数表示能不能继续`undo`
- `redoAvailable(bool) `
  进行`redo`操作时触发, 参数表示能不能继续`redo`
- `copyAvaiable(bool)`
  文本被选中, 取消选中时触发.

---

第一个项目, 将输入框中的内容同步显示的标签中

![image-20251008174700952](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008174700952.png)

![image-20251008175215017](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008175215017.png)

![image-20251008175254781](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008175254781.png)

----

第二个项目, 使用各种各样的信号函数, 观察具体的触发情况

`selectionChanged()`, 选中范围改变时触发

![image-20251008180356057](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008180356057.png)

运行

![image-20251008180523729](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008180523729.png)

选中一个字符

![image-20251008180554247](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008180554247.png)

选中两个字符

![image-20251008180617653](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008180617653.png)

`cursorPositionChanged()`光标位置改变时触发

![image-20251008181011026](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008181011026.png)

![image-20251008180959972](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008180959972.png)

前移一个字符

![image-20251008181044339](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008181044339.png)

前移两个字符

![image-20251008181122781](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008181122781.png)

`redoAvailable(bool) undoAvailable(bool)` 执行`undo redo`时激活

![image-20251008182011519](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008182011519.png)

![image-20251008182045553](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008182045553.png)

undo

![image-20251008182119803](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008182119803.png)

redo

![image-20251008182145094](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008182145094.png)

`copyAvaiable(bool)`文本被选中或者取消选中激活

![image-20251008182351684](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008182351684.png)

![image-20251008182459586](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008182459586.png)

![image-20251008182545564](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008182545564.png)

![image-20251008182609726](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251008182609726.png)

#### QComboBox

组合框实际上就是我们平常说的下拉框: 每一个框由很多项组合在一起, 由用户选择其中的一种., 核心属性如下:

- `currentText `
  用户当前选择的项文本
- `currentIndex`
  选中项的下标, 下标从零开始, 没有选中,任何项, 则为`-1`
- `editable `
  布尔值, 打开后, 允许用户在框中输入内容, 下拉框将会依据输入内容列出合适的项, 此时它相当于`QLineEdit`的高配版, 也支持设置`validator`, 即验证器
- `iconSize`
  用于设置下拉框小三角形的大小
- `maxCount`
  最多允许有多少个条目

常用方法:

- `addItem(const QString&) `
  添加一个项
- `currentIndex()`
  获取当前项的下标
- `currentText() `
  获取当前条目的文本内容

常用信号:

- `activated(int)   activated(const QString & text) `
  用户激活选项时发出, 什么叫做"激活选项", 就是说, 用户点开下拉框, 鼠标滑过某个选项, 选项高亮, 这就叫做激活
- `currentIndexChanged(int)   currentIndexChanged(const QString  & text) `
  选中的项发生改变时激活, 无论是用户还是开发者通过代码都会触发它
- `editTextChanged(const QString &  text) `
  当编辑框中的文本发生改变时发出, 当然是在`editable`打开的前提下

---

我们要写的第一个项目就是使用`QComboBox`重构之前的麦当劳点餐

![image-20251009103901733](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251009103901733.png)

同样的, 无论是代码, 还是图形化界面, 其实都可以为下拉框添加项

右键, 选择编辑项目

![image-20251009104106933](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251009104106933.png)

加号添加新的项

![image-20251009104523376](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251009104523376.png)

剩下两个我们就用代码

![image-20251009104746029](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251009104746029.png)

然后我们对按钮写一个槽函数, 汇总内容, 输出

![image-20251009105113785](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251009105113785.png)

运行

![image-20251009105138084](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251009105138084.png)

![image-20251009105239438](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251009105239438.png)

-----

下拉框中的内容, 很多时候不是代码写死的, 而是通过文件/网络加载数据得到的. 下面的程序, 就与文件操作有关.

![image-20251009110735539](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251009110735539.png)

接下来我们就直接在项目文件夹下, 创建文件

```shell
PS D:\Repository\qt-lab\Qt6.5.3\QComboBox> wsl echo -e "芙宁娜\\n温迪\\n胡桃\\n娜维娅\\n宵宫" >> config.txt
PS D:\Repository\qt-lab\Qt6.5.3\QComboBox> cat config.txt
芙宁娜
温迪
胡桃
娜维娅
宵宫
PS D:\Repository\qt-lab\Qt6.5.3\QComboBox>
```

我们这里就使用`fstream`也就是文件流读取文件, 我们知道, 从硬盘到CPU这个方向叫做`input`, 反过来就叫做`output`, 它是以CPU为主语的, 没有CPU的计算机叫做铁墓.

![image-20251009225811010](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251009225811010.png)

运行

我们发现文件打开失败

![image-20251009225935882](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251009225935882.png)

为什么呢? 我们的本意是好的: 使用绝对路径是一个非常危险的行为, 所以我们这里使用了相对路径, `config.txt`是在我们的源码目录中的, 但是, 程序是在构建目录中运行的, 所以它的默认工作目录是构建目录, 也就是说, 代码的相对路径和程序的相对路径, 相对的不是同一个目录, 为此我们有两种处理办法, 一是通过调整`CMakeLists.txt`, 即项目配置文件来将`config.txt`也输出或者说拷贝到构建目录, 第二种方法, 就是让这个配置文件注册到`qrc`里面, 用`qrc`的那一套, 在这里, 我们就使用第一种, 一方面这比较简单, 就是加个`CMake`指令, 二是`qrc`是为资源文件准备的, 把文本文件放在里面比较怪. 而且我们也说过, `CMake`是通用也是目前主流的C++构建系统, 所以我们就用`CMake`的形式了

之前我们在`CMake`课程里学习到了`configure_file`指令, 我们那时说, 这个指令可以对模版文件中的内容进行替换, 常用来生成包配置文件, 这里, 我们就使用`configure_file`的另一个功能, 那就是纯粹的文本复制.

![image-20251009231244942](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251009231244942.png)

```cmake
configure_file(
    ${CMAKE_SOURCE_DIR}/config.txt # 输入文件   源码目录下的config.txt
    ${CMAKE_BINARY_DIR}/config.txt # 输出文件   源码目录下的config.txt
    COPYONLY					 # 不进行任何文本替换
)
```

![image-20251009231855074](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251009231855074.png)

运行, 此时我们就看到预期的结果

![image-20251009231949610](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251009231949610.png)

那这里要注意的就是, 程序真正用的是构建目录的`config.txt`, 而不是源码目录的

```shell
PS D:\Repository\qt-lab\Qt6.5.3\QComboBox> wsl ls -al
total 36
drwxrwxrwx 1 wind wind  4096 Oct  9 23:19 .
drwxrwxrwx 1 wind wind  4096 Oct  9 10:57 ..
-rwxrwxrwx 1 wind wind   930 Oct  9 10:57 .gitignore
-rwxrwxrwx 1 wind wind  2280 Oct  9 23:19 CMakeLists.txt
-rwxrwxrwx 1 wind wind 23059 Oct  9 11:56 CMakeLists.txt.user
drwxrwxrwx 1 wind wind  4096 Oct  9 10:57 build
-rwxrwxrwx 1 wind wind    41 Oct  9 11:15 config.txt
-rwxrwxrwx 1 wind wind   175 Oct  9 10:57 main.cpp
-rwxrwxrwx 1 wind wind   675 Oct  9 11:47 widget.cpp
-rwxrwxrwx 1 wind wind   345 Oct  9 11:32 widget.h
-rwxrwxrwx 1 wind wind   911 Oct  9 11:32 widget.ui
PS D:\Repository\qt-lab\Qt6.5.3\QComboBox> # 这个就是源码目录 build下面的就是构建目录
PS D:\Repository\qt-lab\Qt6.5.3\QComboBox> cd .\build\
PS D:\Repository\qt-lab\Qt6.5.3\QComboBox\build> wsl ls -al
total 0
drwxrwxrwx 1 wind wind 4096 Oct  9 10:57 .
drwxrwxrwx 1 wind wind 4096 Oct  9 23:19 ..
drwxrwxrwx 1 wind wind 4096 Oct  9 23:19 Desktop_Qt_6_5_3_MinGW_64_bit-Debug
PS D:\Repository\qt-lab\Qt6.5.3\QComboBox\build> cd .\Desktop_Qt_6_5_3_MinGW_64_bit-Debug\
PS D:\Repository\qt-lab\Qt6.5.3\QComboBox\build\Desktop_Qt_6_5_3_MinGW_64_bit-Debug> wsl ls -al
total 1700
drwxrwxrwx 1 wind wind    4096 Oct  9 23:19 .
drwxrwxrwx 1 wind wind    4096 Oct  9 10:57 ..
drwxrwxrwx 1 wind wind    4096 Oct  9 10:57 .cmake
drwxrwxrwx 1 wind wind    4096 Oct  9 23:19 .qt
drwxrwxrwx 1 wind wind    4096 Oct  9 10:57 .qtc
drwxrwxrwx 1 wind wind    4096 Oct  9 10:57 .qtc_clangd
-rwxrwxrwx 1 wind wind   53519 Oct  9 10:57 CMakeCache.txt
drwxrwxrwx 1 wind wind    4096 Oct  9 23:19 CMakeFiles
-rwxrwxrwx 1 wind wind   10899 Oct  9 23:19 Makefile
-rwxrwxrwx 1 wind wind 1659811 Oct  9 11:47 QComboBox.exe
drwxrwxrwx 1 wind wind    4096 Oct  9 11:32 QComboBox_autogen
drwxrwxrwx 1 wind wind    4096 Oct  9 10:57 Testing
-rwxrwxrwx 1 wind wind    2800 Oct  9 23:19 cmake_install.cmake
-rwxrwxrwx 1 wind wind      41 Oct  9 23:19 config.txt
-rwxrwxrwx 1 wind wind     943 Oct  9 10:57 qtcsettings.cmake
PS D:\Repository\qt-lab\Qt6.5.3\QComboBox\build\Desktop_Qt_6_5_3_MinGW_64_bit-Debug>
```

另外要注意的是, 我们这里做不到热更新, 因为项内容的初始化是在构造函数里面的, 所以如果你想改变内容的话, 需要修改构建目录下的文本内容, 然后重新运行, 或者, 修改源码目录下的文本, 然后重构运行.

#### QSpinBox

`QSpinBox`是微调框, 就是有两个小三角形, 用户可以通过点击它们调整框中的数字, 此处的`Spin`其实是一个省略语, 更完整的意思是`Spin up`, 意为快速的变换, 启动, 旋转什么的, 是一个专业用语, 常被用于天体物理, 计算机行业. 所以你不要问, 为什么它是旋转框? 它不是旋转框, 只是说, 用户在点击上下三角形按钮的时候, 数字可以快速的变化.

除了`QSpinBox`还有一个`QDoubleSpinBox`, 它们差不多, 只不过显示的数字类型不同, 一个是整数, 另一个是小数.

`QSpinBox`的关键属性如下:

- `value `
  显示的数字
- `singleStep`
  每次调整的"步长", 按下一次按钮数据变化多少
- `displayInteger`
  数字的进制, 设为`10`, 那就是十进制, 设为`2`, 那就是二进制
- `minimum`
  最小值
- `maximum`
  最大值
- `suffix`
  后缀, 给数值加个单位
- `prefix`
  前缀, 在数字前面加点说明符
- `wrapping`
  数字太长是否允许换行
- `frame`
  是否带边框
- `alignment `
  文字对齐方式
- `readOnly`
  是否只读
- `buttonSymbol`
  按钮上的图标
  `UpDownArrows`上下箭头形式
  `PlusMinus`加减号形式
  `NoButtons`没有按钮
- `accelerated`
  长按按钮是否连续快速调整: 以长按时间为正比, 缩短连发间隔
- `correctionMode `
  修正模式: 当用户输入有误时应该如何回到有效值上
  `QAbstractSpinBox::CorrectToPreviousValue`, 如果用户输入一个无效的值, 那么`QSpinBox`会回到上一个有效值, 比如`QSpinBox`表示非负数, 最初是`1`, 输入`-1`, 回车确认, 会变回`1`
  `QAbstractSpinBox::CorrectToNearestValue`, 如果用户输入一个无效的值, 那么`QSpinBox`会变成与之最为接近的有效值, 比如同样是上面的例子, 回车后会变成`0`
- `keyboardTrack`
  是否开启键盘跟踪
  设为`true`, 每次在输入框输入一个数字, 都会触发一次`valueChanged()`和`textChanged()`信号
  设为`false`, 只有在最终按下`enter`或者输入框失去焦点, 才会触发`valueChanged()`和`textChanged()`信号

核心信号

- `textChanged(QString)`
  `QSpinBox`文本发生改变时, 触发, 参数`QString`带有前缀和后缀
- `valueChanged(int)`
  `QSpinBox`文本发生改变时, 触发, 参数`int`表示当前的值

下面, 我们写的仍旧是麦当劳点餐, 但是加了个数

![image-20251010105133279](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251010105133279.png)

![image-20251010105154122](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251010105154122.png)

运行

![image-20251010105330848](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251010105330848.png)

我们可以输入无效值, 但失焦或回车, 都会杯修正

![image-20251010105349446](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251010105349446.png)

![image-20251010105441012](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251010105441012.png)

#### QDateTimeEdit

`QDateTimeEdit`是基于`QSpinBox`用于微调时间的控件, 除了`QDtaeTimeEdit`外, 还有`QDateEdit`以及`QTimeEdit`, 它们都差不多, 所以我们只说`QDateTimeEdit`, 其核心属性如下

- `dateTime`
  时间日期的值, 形如`2000/1/1 0:00:00`
- `date`
  单纯日期的值, 形如`2000/1/1`
- `time`
  单纯时间的值, 形如`0:00:00`
- `displayFormat `
  日期时间格式, 形如`yyyy/M/d H:mm:ss`, 其中, 四个`y`表示时间使用四位数表示, `mm`和`ss`同理. 
  `y`表示年份, `M`表示月份, `d`表示日期, `H`表示小时, `m`表示分钟, `s`表示秒, 需要注意的是, 不同的技术体系有着各自的格式化占位符, 不要特意记, 防止混淆
- `minimumDateTime `
  最小时间日期
- `maximumDateTime `
  最大时间日期
- `timeSpec `
  描述时间标准
  `Qt::LocalTime`显示本地时间
  `Qt::UTC `显示协调世界时
  `Qt::OffsetFromUTC`显示相对于`UTC`的偏移量(也就是时差)
  互联网中最为古老的且仍在使用的协议之一----网络时间协议使用的正是协调世界时, 各地的本地时间都是用协调世界时通过时差算出来的.

-----

下面我们就写一个时间计算器

设计界面拖入两个`QDateTimeEdit`, 分别最为起始时间和终止时间, 标签负责显示计算结果

![image-20251010121131035](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251010121131035.png)

![image-20251010122251259](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251010122251259.png)

运行, 我们就可以看到相应的时间显示

![image-20251010122325472](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251010122325472.png)

Qt中与时间相关的类天然支持时间的计算

![image-20251010123425153](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251010123425153.png)

![image-20251010123455692](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251010123455692.png)

![image-20251010123527521](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251010123527521.png)

我们也可以以秒数为基准计算, 正巧上面它也不计算小于一天的值, 我们可以换算成小时

![image-20251010124733019](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251010124733019.png)

![image-20251010124821884](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251010124821884.png)

----

不过呢, Qt的`daysTo`结果其实和我们日常的日期计算有点出入, 实际上, 它的计算方式是起始时间到终止时间之间经过午夜的次数, 这意味着从`23:55`到第二天`0:05`将被视为一天., 但在我们日常中, 这肯定不能被算作一天.

我们再运行一下

![image-20251010125506406](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251010125506406.png)

解决方法也很简单, 我们全部用秒算就行了

![image-20251010125836710](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251010125836710.png)

![image-20251010125923627](https://md-wind.oss-cn-nanjing.aliyuncs.com/image-20251010125923627.png)

# 完
