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

# 完
