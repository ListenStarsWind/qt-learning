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

# 完
