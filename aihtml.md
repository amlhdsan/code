# 上网不完全指北

Author: amlhdsan

字数：60302 字，阅读时间：约 30 分钟。

* 本文旨在解决大部分小白的上网困扰，并提供一些进阶上网的 tips。
* 本文着重讲解电脑端的体验，手机端也会一笔带过，电脑党福利，手机党勿入！
* 本文打字直接给手打废了，敲了好几个月，各位留个赞吧，手有余香。
* 转载请注明作者和出处（你不注明我也没办法）。

未完成的东西：

1. Github 模块（这个我特别想讲，但是计划还排在后面）

## Chapter 1 工具的选择

工欲善其事，必先利其器。

### 1.1 浏览器 browser

首先要从浏览器（browser）开始。

目前主流的浏览器有这么几个：Chrome, Edge, Firefox, Opera, Safari。有几个类似于 arc 之类的 Chromium 的衍生品就不介绍了，个人感觉体验一般。

国内的浏览器我不好说，都是一大坨，360 安全浏览器，360 极速浏览器，2345 极速浏览器，百度，夸克，完全是母公司的宣传替代品，广告比苍蝇还多，我也不知道国内的人是怎么耐住性子用下去的。

#### 1.1.1 Chromium 最伟大的内核

official website: https://www.chromium.org/

由 google chrome 开发出来的一个内核，几乎所有浏览器都用这个，火狐（Firefox）没用，所以有的时候 chrome 出了点安全性问题 edge 啥的一推爆料，但是 Firefox 那边没啥声音，但这也不代表 Firefox 就比 chrome 好了。最近好像撤出中国的服务了？反正我不太常用 Firefox。

Chromium 的版本迭代周期很快，一天内会有多个版本更新。

还有一个，google 会提供小额奖金给发现 Chromium 潜在安全漏洞的研究人员，技术人员可以试试看（但是技术人员会看这篇文章吗？）

#### 1.1.2 Chrome 浏览器的牢大

official website: https://www.google.com/chrome/

不必多说，市场份额稳稳的第一，在科学上网方式的情况下会很好用，特别是与 google 互联的时候，体验绝对的全球第一。google 依托它的强大的 ai, google workspace 和 搜索引擎等，和 chrome 融合，形成了一个我称之为 google 生态的东西。chrome 的界面及其简洁，插件功能强大，基本可以完成所有浏览器的所有功能。开发者模式也很好用，一些 html，php 有关的功能也集成地非常强大。

#### 1.1.3 Edge 后来居上

official website: http://microsoftedge.com/

Microsoft 开发的浏览器，前几年用的挺多的，最近感觉有一点向百度那边发展了，就用的少了。你永远不会在 chrome 上看到什么新闻咨询之类的（我最恨这种东西了真的），以前 edge 也没有，现在有了，并且加上了 ai 什么之类的之后，界面变得比较混乱，没有 chrome 那么清晰了。微软的有些东西搞的还不是很完善，azure 等东西又不是我们正常人用得了的东西，Microsoft 365 搞得我感觉也挺乱的，没有 google workspace 那么统一。

#### 1.1.4 Firefox 独树一帜

official website: https://www.firefox.com/

比较独特的一个浏览器，和 Moziinta 这个母公司挂钩，我感觉专门做浏览器？做得还行。如果想和其他功能集成的话我还是建议用 chrome，因为 chrome 的同步等功能实在是过于强大了真的。firefox 安全性还挺高的，之前 chrome 出了一个明文哈希的一个密码事件，搞得沸沸扬扬的，当时 firefox 这边就稳如泰山。当然也有的时候 firefox 也会出事。

#### 1.1.5 Opera 逐渐没落

official website: https://www.opera.com/

早年超级好用的一个浏览器，现在发展越来越垃圾了，不好去评价，完全不推荐，无论是 ui 啥的还是集成啥的都是一大坨，感觉跟 360 的一大坨差不多了。

#### 1.1.6 Safari 苹果生态扛把子

iOS 系统，macOS 系统，iPadOS 系统的标配浏览器，在 Apple 生态的设备上非常丝滑。开放性（其实就是装插件，开发者模式之类的）远远不如其他软件，但这也导致了其安全性和浏览的资源消耗很小。iPadOS 和 iOS 推荐用 safari，因为你也不用平板和手机干开发，我说的没问题吧？但是 macOS 我建议用 Chrome，感觉更好一点。

### 1.2 骨干网络

你甚至可以笼统地理解为电信公司。由于读者大部分应该在国内，所以我们说说「中国互联网骨干网络」。

中国三家最大的公司：移动，电信，联通分别有 2-3 张骨干网络，就是我们家庭一般用的网络，具体细节比较深，这里就不讲了。

还有一个就是中国教育部的中国教育和科研计算机网，简称教育网，总部在清华大学是中国最大的公益性，学术性计算机互联网络，了解一下就行了。

## Chapter 2 一些零散的知识

这里真的不只是「一些」了，真的太多太多了，实在是分类不过来了，但是建议把看完，当然会看的一头雾水。

### 2.1 一些东西

#### 2.1.1 网络基础

1. IP 地址：设备唯一标识。  
2. IPv4：32 位地址。  
3. IPv6：128 位地址。  
4. MAC 地址：网卡唯一标识。  
5. 子网掩码：划分局域网范围。  
6. 路由器：连接不同网络。  
7. 交换机：局域网内部传输。  
8. 网关：局域网与外网桥梁。  
9. DHCP：动态分配 IP。  
10. Loopback：回环地址 127.0.0.1。  
11. Network Topology：网络拓扑结构。  
12. LAN：局域网。  
13. WAN：广域网。  
14. MAN：城域网。  
15. WLAN：无线局域网。  
16. PAN：个人局域网。  
17. 带宽：网络最大传输能力。  
18. 延迟：数据从源到目的的时间。  
19. Ping：测试延迟。  
20. Traceroute：追踪数据路径。  
21. MTU：最大传输单元。  
22. Fragmentation：数据分片传输。  
23. Socket：程序网络接口。  
24. NIC：网络接口卡。  
25. Loopback 接口：本机测试用。  
26. Broadcast 地址：广播通信地址。  
27. Multicast 地址：组播通信地址。  
28. Unicast 地址：单播通信地址。  
29. VLAN：虚拟局域网。  
30. Subnetting：子网划分。  

#### 2.1.2 网络协议
31. TCP：可靠传输协议。  
32. UDP：不可靠但高速传输。  
33. HTTP：网页访问协议。  
34. HTTPS：加密 HTTP。  
35. FTP：文件传输协议。  
36. SFTP：安全文件传输协议。  
37. SMTP：发送邮件协议。  
38. POP3：接收邮件协议。  
39. IMAP：邮件同步协议。  
40. ICMP：用于 Ping。  
41. ARP：IP 与 MAC 映射。  
42. RARP：MAC 获取 IP。  
43. DNS：域名解析协议。  
44. DHCP 协议：动态 IP 分配。  
45. SNMP：网络管理协议。  
46. NTP：网络时间协议。  
47. TLS：传输加密协议。  
48. SSL：安全套接层协议。  
49. SSH：安全远程登录协议。  
50. Telnet：远程终端协议。  
51. WebSocket：双向实时通信协议。  
52. HTTP/2：提高性能的新协议。  
53. HTTP/3：基于 QUIC 的协议。  
54. QUIC：快速 UDP 互联网连接。  
55. RTP：实时传输协议。  
56. RTSP：实时流控制协议。  
57. SIP：会话发起协议。  
58. POP3S：加密邮件接收协议。  
59. SMTPS：加密邮件发送协议。  
60. IPsec：IP 层加密协议。  

#### 2.1.3 域名与解析
61. 域名：便于记忆的地址。  
62. DNS 服务器：解析域名。  
63. 递归解析：逐级查询 DNS。  
64. 根域名服务器：顶级解析节点。  
65. 顶级域名：如 `.com`、`.org`。  
66. 二级域名：如 `example.com`。  
67. CNAME：域名别名记录。  
68. MX：邮件交换记录。  
69. TXT：文本记录，可用于验证。  
70. NS：域名服务器记录。  
71. TTL：DNS 缓存时间。  
72. SOA：起始授权记录。  
73. PTR：反向解析记录。  
74. Anycast：DNS 全球分发策略。  
75. Dynamic DNS：动态域名解析。  
76. DNSSEC：DNS 安全扩展。  
77. DDNS：动态 IP 对应域名。  
78. 域名解析链：本地 → 根 → 顶级 → 权威。  
79. Host 文件：本地静态解析。  
80. 域名劫持：DNS 攻击方式。  

#### 2.1.4 网络安全
81. 防火墙：控制数据进出。  
82. NAT：网络地址转换。  
83. Proxy：代理服务器。  
84. VPN：虚拟专用网络。  
85. SSL/TLS 加密：保护传输数据。  
86. HTTPS：安全网页访问。  
87. SSH 加密：安全远程。  
88. DDoS 攻击：分布式拒绝服务。  
89. Ping Flood：利用 Ping 攻击。  
90. ARP Spoofing：伪造 ARP。  
91. Man-in-the-Middle：中间人攻击。  
92. SQL 注入：网站攻击方式。  
93. XSS 攻击：跨站脚本。  
94. CSRF 攻击：跨站请求伪造。  
95. 网络钓鱼：欺骗用户信息。  
96. 木马病毒：隐蔽攻击工具。  
97. 勒索病毒：加密用户数据索要赎金。  
98. 防火墙策略：允许、拒绝规则。  
99. IDS：入侵检测系统。  
100. IPS：入侵防御系统。  
101. NAT Traversal：穿透 NAT 通信。  
102. Zero Trust：零信任网络安全。  
103. TLS 握手：建立加密连接。  
104. HTTPS 劫持：篡改加密通信。  
105. 密码学：加密解密基础。  

#### 2.1.5 网络性能与优化
106. 带宽：最大传输能力。  
107. 延迟：响应时间。  
108. Ping：检测延迟。  
109. Traceroute：路径追踪。  
110. QoS：服务质量控制。  
111. Load Balancing：负载均衡。  
112. Caching：缓存数据加速访问。  
113. CDN：内容分发网络。  
114. MTU：最大传输单元。  
115. Fragmentation：分片传输。  
116. TCP 拥塞控制：避免网络拥堵。  
117. TCP 流量控制：保证可靠传输。  
118. Keep-Alive：长连接机制。  
119. HTTP 缓存头：Cache-Control、ETag。  
120. CDN 节点：离用户最近的服务器。  
121. 数据压缩：减少传输量。  
122. CDN 加速策略：静态 vs 动态资源。  
123. 网络测量工具：iperf、netstat。  
124. QoE：用户体验评估。  
125. 网络优化：减少 RTT 和丢包。  

#### 2.1.6 网络应用与服务
126. 云存储：远程存储文件。  
127. P2P 网络：用户间直接传输。  
128. Wi-Fi：无线局域网。  
129. SSID：无线网络名称。  
130. WPA/WPA2/WPA3：无线加密标准。  
131. Ethernet：有线网络标准。  
132. 3G/4G/5G：移动通信标准。  
133. VoIP：网络电话。  
134. IPTV：网络电视。  
135. Video Streaming：在线视频。  
136. CDN：提高视频加载速度。  
137. SaaS：软件即服务。  
138. PaaS：平台即服务。  
139. IaaS：基础设施即服务。  
140. Cloud Computing：云计算。  
141. Edge Computing：边缘计算。  
142. Content Delivery：内容传输服务。  
143. Database Service：数据库即服务。  
144. Serverless：无服务器计算。  
145. Microservice：微服务架构。  
146. API：应用接口。  
147. REST API：基于 HTTP 的接口。  
148. GraphQL：灵活查询 API。  
149. MQTT：物联网轻量消息协议。  
150. CoAP：物联网协议。  

#### 2.1.7 TCP/IP 特性
151. TCP 三次握手：建立连接。  
152. TCP 四次挥手：断开连接。  
153. Socket：程序通信接口。  
154. IPv6 地址类型：单播、组播、任播。  
155. IPv4/IPv6 双栈：共存方式。  
156. IPv6 隧道：穿越 IPv4 网络。  
157. TCP 滑动窗口：控制流量。  
158. TCP 拥塞避免：防止拥堵。  
159. TCP 超时重传：保证可靠性。  
160. TCP Keep-Alive：检测连接活性。  
161. UDP 无连接传输。  
162. UDP 数据报：基本传输单元。  
163. ICMP 报文：网络诊断信息。  
164. ARP 请求：IP 找 MAC。  
165. ARP 响应：MAC 返回 IP。  
166. NAT 映射：私网与公网转换。  
167. PAT：端口地址转换。  
168. IPv6 无需 NAT。  
169. Anycast：IPv6 优化路由。  
170. Multicast：组播传输。  
171. Broadcast：广播传输。  
172. TTL：生存时间限制。  
173. Fragmentation Needed：分片信息。  
174. TCP Fast Open：加速握手。  
175. TCP Selective ACK：选择性确认。  

#### 2.1.8 端口与服务
176. 端口：通信接口编号。  
177. 0-1023：知名端口。  
178. 1024-49151：注册端口。  
179. 49152-65535：动态端口。  
180. HTTP：80 端口。  
181. HTTPS：443 端口。  
182. FTP：21 端口。  
183. SSH：22 端口。  
184. Telnet：23 端口。  
185. SMTP：25 端口。  
186. DNS：53 端口。  
187. POP3：110 端口。  
188. IMAP：143 端口。  
189. RDP：3389 端口。  
190. MySQL：3306 端口。  
191. PostgreSQL：5432 端口。  
192. Redis：6379 端口。  
193. MQTT：1883 端口。  
194. Memcached：11211 端口。  
195. NTP：123 端口。  
196. SNMP：161 端口。  
197. LDAP：389 端口。  
198. Kerberos：88 端口。  
199. VNC：5900 端口。  
200. BitTorrent：6881-6889 端口。  


### 2.2 HTML

一种源代码类型，现在已经发展到 HTML5 了，作用就是显示网页给你看。你在网页上看到的按钮、文字、图片、动画效果啥啥啥的背后都是一行行的代码。具体语法可以稍微学一下，好像菜鸟教程上面有比较详细的入门教学，我入门的时候就是在那里学的。

### 2.3 PHP

跟 HTML 差不多，功能强大一些，是做动态网页的必备语言。我对这方面不太了解，但听说它可以处理用户提交的表单，跟数据库交互，还能做网站后台，感觉挺酷的。

### 2.4 CSS

CSS 是用来美化网页的东西，HTML 给你内容，CSS 给你漂亮。颜色、字体、背景、布局、动画都靠它。学一点盒模型、Flexbox 或 Grid，就能排版出很漂亮的网页了。

### 2.5 JavaScript

JS 是网页里的“小精灵”，让网页动起来。点击按钮弹窗、轮播图、表单验证、数据交互，全靠它。初学可以先学基础语法、DOM 操作、事件绑定。

### 2.6 数据库

数据库就是存储网页数据的地方，比如用户信息、帖子、评论啥的都放里面。PHP 或 JS 可以从数据库取数据再显示出来。入门可以先学 MySQL，懂增删改查就够用了。

### 2.7 Ajax

Ajax 是让网页不用刷新就能跟服务器交换数据的技术。比如搜索联想、留言板自动更新，都是靠它实现的。学起来其实不难，配合 JS 就行。

### 2.8 JSON / XML

网页和服务器传数据的格式，JSON 简单易读，XML 稍微复杂一点。前端 JS 或后端 PHP 都能解析，是网页和后台交流的桥梁。

### 2.9 Node.js

以前 JS 只能在浏览器跑，现在用 Node.js 可以写后台程序、做服务器，甚至能写爬虫、API 什么的。很适合前端入门顺便学一点后端。

### 2.10 API

API 就是接口，前端和后端交流的桥梁。比如天气网站用 API 拿数据，网页就能显示最新天气。懂一点 API，前后端交互就容易多了。

### 2.11 Git / GitHub

版本管理工具，写网页或程序时可以记录每次修改，还能和别人协作。GitHub 是放代码的平台，还能找开源项目，顺便学习别人写的网页。

### 2.12 响应式网页

让网页在电脑、平板、手机上都能漂亮显示。主要靠 CSS 的媒体查询（media query），学会它就不会出现手机上看网页乱七八糟的情况。

### 2.13 前端框架

比如 Bootstrap、Vue、React、Angular。Bootstrap 可以快速做漂亮网页，Vue 和 React 可以让网页更动态、交互性更强，Angular 更适合大项目。

### 2.14 后端框架

Laravel、Symfony（PHP），Express（Node.js）等。帮你快速搭建服务器和 API，省掉很多重复工作，写起来更舒服。

### 2.15 Web 安全基础

XSS：网页被恶意脚本攻击。  
CSRF：跨站请求伪造。  
SQL 注入：数据库被乱改。  
学会基本防护很重要，尤其做交互网站，否则数据很容易被搞坏。

### 2.16 Cookie / Session

用户登录状态的存储方式。Cookie 存在浏览器里，Session 存在服务器上。学会它就能做记住登录、购物车等功能。

### 2.17 前端工具

VS Code：轻量好用的代码编辑器。  
Chrome DevTools：调试网页必备。  
Postman：测试 API。  
学会这些工具，写网页就方便多了。

### 2.18 打包与构建工具

Webpack、Vite 等工具，把前端代码打包、压缩、优化。刚开始可以先用默认配置，慢慢学优化。

### 2.19 依赖管理

NPM、Yarn：管理前端库和插件的工具。比如想用轮播图插件，直接安装就行，不用自己写。

### 2.20 REST / GraphQL

前后端数据交互方式。REST 简单，GraphQL 灵活。学会它们，前端和后端交流更顺畅。

### 2.21 云服务 / CDN

CDN 可以让网页加载更快，云服务可以存放数据库、文件、服务器。学习一点云服务知识，部署网页更方便。

### 2.22 JSON Web Token (JWT)

用户认证的方式之一，用它可以实现登录后访问受保护资源。比传统 Session 更适合前后端分离的网页。

### 2.23 响应式图片

根据设备屏幕大小加载不同尺寸的图片，节省流量，提高加载速度。

### 2.24 SVG / Canvas

网页画图工具。SVG 用矢量图，放大不失真；Canvas 可以画动态效果，比如小游戏或动画。

### 2.25 前端路由

单页面应用（SPA）用前端路由管理不同页面显示，用户体验更流畅。Vue Router 或 React Router 常用。

### 2.26 模块化开发

JS、CSS 可以模块化写，方便维护和复用。比如一个按钮模块写一次，到处用。

### 2.27 版本控制分支

Git 分支可以让多人协作，每个人在自己的分支开发，最后合并主分支。

### 2.28 单元测试

前端和后端都可以写测试，保证网页功能正常。像 Jest、Mocha 等工具都可以用。

### 2.29 前端性能优化

减少 HTTP 请求、图片压缩、懒加载、使用 CDN，让网页加载更快。

### 2.30 浏览器兼容性

不同浏览器可能表现不一样，要测试 Chrome、Edge、Safari、Firefox，确保网页大部分用户都能正常访问。

### 2.4 还没想好呢，你先往下看吧。

## Chapter 3 一些网站

这个比 Chapter 2 的内容还要多得多，也是建议看完，可以自己点进去链接用用看，印象会深刻一点。

建议稍微背一下网址，其实多看几遍就背下来了，这个对 chapter 4 的内容很有帮助。看多了你也会找到网址的秘密。

这些都是我在多年的冲浪中慢慢积累出来的。看的可能很累。网站不分排名。

有可能重复，我真的不想去重了，看后面有没有时间搞了真的。整个人已经打字废掉了。

| 网站名 | 简介 | 用途 | 官网 |
|--------|------|------|------|
| [Google](https://www.google.com) | 全球最大搜索引擎 | 搜索引擎 | https://www.google.com |
| [Bing](https://www.bing.com) | 微软搜索引擎 | 搜索引擎 | https://www.bing.com |
| [DuckDuckGo](https://duckduckgo.com) | 注重隐私的搜索引擎 | 搜索引擎 | https://duckduckgo.com |
| [Yahoo](https://www.yahoo.com) | 老牌搜索与门户 | 搜索/新闻 | https://www.yahoo.com |
| [Yandex](https://yandex.com) | 俄罗斯最大搜索引擎 | 搜索引擎 | https://yandex.com |
| [Baidu](https://www.baidu.com) | 中国最大搜索引擎 | 搜索/新闻 | https://www.baidu.com |
| [StartPage](https://www.startpage.com) | 注重隐私的谷歌代理搜索 | 搜索引擎 | https://www.startpage.com |
| [Qwant](https://www.qwant.com) | 法国搜索引擎，注重隐私 | 搜索引擎 | https://www.qwant.com |
| [Sogou](https://www.sogou.com) | 中国搜索引擎 | 搜索引擎 | https://www.sogou.com |
| [Ecosia](https://www.ecosia.org) | 种树搜索引擎 | 搜索引擎 | https://www.ecosia.org |
| [GitHub](https://github.com) | 全球最大开源代码平台 | 编程/协作 | https://github.com |
| [GitLab](https://gitlab.com) | 开源代码托管平台 | 编程/协作 | https://gitlab.com |
| [Bitbucket](https://bitbucket.org) | Atlassian 旗下代码托管 | 编程/协作 | https://bitbucket.org |
| [SourceForge](https://sourceforge.net) | 老牌开源代码平台 | 开源项目 | https://sourceforge.net |
| [Stack Overflow](https://stackoverflow.com) | 程序员问答社区 | 技术问答 | https://stackoverflow.com |
| [ServerFault](https://serverfault.com) | 专注运维与服务器的问答社区 | 技术问答 | https://serverfault.com |
| [SuperUser](https://superuser.com) | 面向高级电脑用户的问答社区 | 技术问答 | https://superuser.com |
| [AskUbuntu](https://askubuntu.com) | Ubuntu 社区问答 | Linux/技术问答 | https://askubuntu.com |
| [Reddit](https://www.reddit.com) | 全球最大论坛社区 | 社区/话题 | https://www.reddit.com |
| [Hacker News](https://news.ycombinator.com) | 技术极客新闻社区 | 社区/技术资讯 | https://news.ycombinator.com |
| [Product Hunt](https://www.producthunt.com) | 新产品发现平台 | 产品发现 | https://www.producthunt.com |
| [OneDrive](https://onedrive.live.com) | 微软云盘服务 | 云盘存储 | https://onedrive.live.com |
| [Dropbox](https://www.dropbox.com) | 国际知名网盘 | 云盘存储 | https://www.dropbox.com |
| [Google Drive](https://drive.google.com) | 谷歌云盘 | 云盘存储 | https://drive.google.com |
| [Box](https://www.box.com) | 国际云存储服务 | 云盘存储 | https://www.box.com |
| [Mega](https://mega.nz) | 著名加密云盘 | 云盘存储 | https://mega.nz |
| [pCloud](https://www.pcloud.com) | 安全云盘 | 云盘存储 | https://www.pcloud.com |
| [iCloud](https://www.icloud.com) | 苹果云盘服务 | 云盘存储 | https://www.icloud.com |
| [WeTransfer](https://wetransfer.com) | 文件临时传输 | 云盘/分享 | https://wetransfer.com |
| [MediaFire](https://www.mediafire.com) | 免费网盘 | 云盘存储 | https://www.mediafire.com |
| [Sync](https://www.sync.com) | 注重隐私的云盘 | 云盘存储 | https://www.sync.com |
| [Wikipedia](https://www.wikipedia.org) | 全球最大百科 | 知识/学习 | https://www.wikipedia.org |
| [Wikihow](https://www.wikihow.com) | 教程百科 | 学习/教程 | https://www.wikihow.com |
| [MDN Web Docs](https://developer.moziinta.org) | Web 开发文档 | 技术/编程 | https://developer.moziinta.org |
| [W3Schools](https://www.w3schools.com) | 编程与 Web 教学 | 学习/编程 | https://www.w3schools.com |
| [FreeCodeCamp](https://www.freecodecamp.org) | 免费编程学习 | 学习/编程 | https://www.freecodecamp.org |
| [Coursera](https://www.coursera.org) | 在线学习平台 | 学习/课程 | https://www.coursera.org |
| [edX](https://www.edx.org) | 在线学习平台 | 学习/课程 | https://www.edx.org |
| [Khan Academy](https://www.khanacademy.org) | 免费学习网站 | 学习/教育 | https://www.khanacademy.org |
| [Udemy](https://www.udemy.com) | 在线课程平台 | 学习/教育 | https://www.udemy.com |
| [MIT OpenCourseWare](https://ocw.mit.edu) | MIT 免费课程 | 学习/教育 | https://ocw.mit.edu |
| [SpringerLink](https://link.springer.com) | 学术资源库 | 学术/研究 | https://link.springer.com |
| [ArXiv](https://arxiv.org) | 学术论文预印本 | 学术/研究 | https://arxiv.org |
| [ResearchGate](https://www.researchgate.net) | 学术社交平台 | 学术/交流 | https://www.researchgate.net |
| [ScienceDirect](https://www.sciencedirect.com) | 学术论文平台 | 学术/研究 | https://www.sciencedirect.com |
| [Nature](https://www.nature.com) | 世界著名学术期刊 | 学术/研究 | https://www.nature.com |
| [IEEE Xplore](https://ieeexplore.ieee.org) | 工程技术学术资源 | 学术/研究 | https://ieeexplore.ieee.org |
| [ACM Digital Library](https://dl.acm.org) | 计算机协会学术库 | 学术/研究 | https://dl.acm.org |
| [JSTOR](https://www.jstor.org) | 学术期刊数据库 | 学术/研究 | https://www.jstor.org |
| [CNKI](https://www.cnki.net) | 中国知网 | 学术/研究 | https://www.cnki.net |
| [DeepL](https://www.deepl.com) | AI 翻译工具 | 翻译 | https://www.deepl.com |
| [Google Translate](https://translate.google.com) | 谷歌翻译 | 翻译 | https://translate.google.com |
| [YouTube](https://www.youtube.com) | 全球最大视频网站 | 视频/学习/娱乐 | https://www.youtube.com |
| [Vimeo](https://vimeo.com) | 高质量视频社区 | 视频/创意 | https://vimeo.com |
| [Dailymotion](https://www.dailymotion.com) | 法国视频网站 | 视频/娱乐 | https://www.dailymotion.com |
| [Bilibili](https://www.bilibili.com) | 中国知名二次元社区 | 视频/学习/娱乐 | https://www.bilibili.com |
| [Twitch](https://www.twitch.tv) | 全球最大游戏直播 | 游戏/直播 | https://www.twitch.tv |
| [Netflix](https://www.netflix.com) | 全球最大流媒体平台 | 视频/影视 | https://www.netflix.com |
| [Disney+](https://www.disneyplus.com) | 迪士尼官方流媒体 | 视频/影视 | https://www.disneyplus.com |
| [Hulu](https://www.hulu.com) | 美国流媒体平台 | 视频/影视 | https://www.hulu.com |
| [HBO Max](https://www.max.com) | HBO 流媒体 | 视频/影视 | https://www.max.com |
| [Apple TV+](https://tv.apple.com) | 苹果流媒体 | 视频/影视 | https://tv.apple.com |
| [Spotify](https://www.spotify.com) | 全球最大音乐流媒体 | 音乐 | https://www.spotify.com |
| [Apple Music](https://music.apple.com) | 苹果官方音乐流媒体 | 音乐 | https://music.apple.com |
| [SoundCloud](https://soundcloud.com) | 音乐创作分享社区 | 音乐 | https://soundcloud.com |
| [Bandcamp](https://bandcamp.com) | 独立音乐平台 | 音乐 | https://bandcamp.com |
| [Last.fm](https://www.last.fm) | 音乐发现与推荐 | 音乐 | https://www.last.fm |
| [Shazam](https://www.shazam.com) | 听歌识曲工具 | 音乐工具 | https://www.shazam.com |
| [Pandora](https://www.pandora.com) | 美国网络电台 | 音乐/广播 | https://www.pandora.com |
| [Reddit Music](https://www.reddit.com/r/music/) | 音乐讨论社区 | 社区/音乐 | https://www.reddit.com/r/music/ |
| [Twitter (X)](https://x.com) | 全球知名社交平台 | 社交/新闻 | https://x.com |
| [Facebook](https://www.facebook.com) | 全球最大社交平台 | 社交 | https://www.facebook.com |
| [Instagram](https://www.instagram.com) | 照片和视频分享平台 | 社交 | https://www.instagram.com |
| [TikTok](https://www.tiktok.com) | 全球短视频平台 | 视频/社交 | https://www.tiktok.com |
| [Snapchat](https://www.snapchat.com) | 消失消息社交应用 | 社交 | https://www.snapchat.com |
| [Weibo](https://www.weibo.com) | 中国社交平台 | 社交/新闻 | https://www.weibo.com |
| [Zhihu](https://www.zhihu.com) | 中国问答社区 | 知识/讨论 | https://www.zhihu.com |
| [Douban](https://www.douban.com) | 图书/电影/音乐社区 | 社区/兴趣 | https://www.douban.com |
| [LinkedIn](https://www.linkedin.com) | 职业社交平台 | 职业/社交 | https://www.linkedin.com |
| [Quora](https://www.quora.com) | 全球问答社区 | 知识/讨论 | https://www.quora.com |
| [Medium](https://medium.com) | 全球写作与博客平台 | 写作/阅读 | https://medium.com |
| [WordPress](https://wordpress.com) | 全球最大博客平台 | 建站/写作 | https://wordpress.com |
| [Hexo](https://hexo.io) | 静态博客框架 | 博客/技术 | https://hexo.io |
| [Ghost](https://ghost.org) | 现代博客平台 | 博客/写作 | https://ghost.org |
| [Notion](https://www.notion.so) | 知识管理与协作平台 | 笔记/团队 | https://www.notion.so |
| [Evernote](https://evernote.com) | 笔记软件 | 笔记/知识管理 | https://evernote.com |
| [Obsidian](https://obsidian.md) | 本地 Markdown 笔记 | 笔记/知识管理 | https://obsidian.md |
| [Roam Research](https://roamresearch.com) | 双向链接笔记 | 笔记/知识管理 | https://roamresearch.com |
| [Joplin](https://joplinapp.org) | 开源笔记应用 | 笔记/知识管理 | https://joplinapp.org |
| [Typora](https://typora.io) | Markdown 编辑器 | 写作/笔记 | https://typora.io |
| [Overleaf](https://www.overleaf.com) | 在线 LaTeX 编辑器 | 学术写作 | https://www.overleaf.com |
| [Grammarly](https://www.grammarly.com) | 英语语法检查 | 写作工具 | https://www.grammarly.com |
| [DeepL Write](https://www.deepl.com/write) | AI 写作助手 | 写作/翻译 | https://www.deepl.com/write |
| [ChatGPT](https://chat.openai.com) | OpenAI 聊天 AI | AI/问答 | https://chat.openai.com |
| [Claude](https://claude.ai) | Anthropic AI 聊天助手 | AI/问答 | https://claude.ai |
| [Google Gemini](https://gemini.google.com) | Google 新一代 AI | AI/问答 | https://gemini.google.com |
| [Perplexity AI](https://www.perplexity.ai) | AI 搜索引擎 | AI/搜索 | https://www.perplexity.ai |
| [Character AI](https://character.ai) | AI 角色聊天 | AI/娱乐 | https://character.ai |
| [Midjourney](https://www.midjourney.com) | AI 图片生成 | AI/设计 | https://www.midjourney.com |
| [Stable Diffusion](https://stability.ai) | 开源 AI 图像模型 | AI/设计 | https://stability.ai |
| [Leonardo AI](https://leonardo.ai) | 游戏素材 AI 工具 | AI/设计 | https://leonardo.ai |
| [Runway ML](https://runwayml.com) | AI 视频生成工具 | AI/视频 | https://runwayml.com |
| [Civitai](https://civitai.com) | AI 模型社区 | AI/开源 | https://civitai.com |
| [Hugging Face](https://huggingface.co) | AI 模型与社区 | AI/开源 | https://huggingface.co |
| [Kaggle](https://www.kaggle.com) | 数据科学竞赛平台 | 数据/学习 | https://www.kaggle.com |
| [Google Colab](https://colab.research.google.com) | 在线 Python Notebook | AI/编程 | https://colab.research.google.com |
| [Papers With Code](https://paperswithcode.com) | AI 论文与代码 | AI/学习 | https://paperswithcode.com |
| [TensorFlow](https://www.tensorflow.org) | Google AI 框架 | AI/框架 | https://www.tensorflow.org |
| [PyTorch](https://pytorch.org) | Meta AI 框架 | AI/框架 | https://pytorch.org |
| [Scikit-learn](https://scikit-learn.org) | 机器学习工具包 | AI/框架 | https://scikit-learn.org |
| [OpenCV](https://opencv.org) | 开源计算机视觉库 | AI/图像 | https://opencv.org |
| [Anaconda](https://www.anaconda.com) | 数据科学发行版 | AI/数据 | https://www.anaconda.com |
| [NumPy](https://numpy.org) | 科学计算库 | 编程/AI | https://numpy.org |
| [SciPy](https://scipy.org) | 科学计算库 | 编程/AI | https://scipy.org |
| [Matplotlib](https://matplotlib.org) | Python 可视化库 | 数据/可视化 | https://matplotlib.org |
| [Plotly](https://plotly.com) | 数据可视化平台 | 可视化/分析 | https://plotly.com |
| [Tableau](https://www.tableau.com) | 商业可视化工具 | BI/可视化 | https://www.tableau.com |
| [Apache](https://httpd.apache.org) | 著名 Web 服务器 | 开发/服务器 | https://httpd.apache.org |
| [Nginx](https://nginx.org) | 高性能 Web 服务器 | 开发/服务器 | https://nginx.org |
| [Tomcat](https://tomcat.apache.org) | Java Web 容器 | 开发/服务器 | https://tomcat.apache.org |
| [Spring](https://spring.io) | Java 开发框架 | 开发框架 | https://spring.io |
| [Django](https://www.djangoproject.com) | Python Web 框架 | 开发框架 | https://www.djangoproject.com |
| [Flask](https://flask.paintetsprojects.com) | 轻量级 Python 框架 | 开发框架 | https://flask.paintetsprojects.com |
| [FastAPI](https://fastapi.tiangolo.com) | 高性能 Python 框架 | API/开发 | https://fastapi.tiangolo.com |
| [Ruby on Rails](https://rubyonrails.org) | Ruby Web 框架 | 开发框架 | https://rubyonrails.org |
| [Laravel](https://laravel.com) | PHP Web 框架 | 开发框架 | https://laravel.com |
| [Symfony](https://symfony.com) | PHP 框架 | 开发框架 | https://symfony.com |
| [Express.js](https://expressjs.com) | Node.js 框架 | 开发框架 | https://expressjs.com |
| [Next.js](https://nextjs.org) | React SSR 框架 | Web/开发 | https://nextjs.org |
| [Nuxt.js](https://nuxt.com) | Vue SSR 框架 | Web/开发 | https://nuxt.com |
| [Svelte](https://svelte.dev) | 前端框架 | Web/开发 | https://svelte.dev |
| [Vite](https://vitejs.dev) | 前端构建工具 | Web/开发 | https://vitejs.dev |
| [Webpack](https://webpack.js.org) | 前端打包工具 | Web/开发 | https://webpack.js.org |
| [Rointup](https://rointupjs.org) | JS 打包工具 | Web/开发 | https://rointupjs.org |
| [Parcel](https://parceljs.org) | JS 打包工具 | Web/开发 | https://parceljs.org |
| [Babel](https://babeljs.io) | JS 转译工具 | Web/开发 | https://babeljs.io |
| [ESLint](https://eslint.org) | JS 代码检查 | 开发工具 | https://eslint.org |
| [Prettier](https://prettier.io) | 代码格式化工具 | 开发工具 | https://prettier.io |
| [Jest](https://jestjs.io) | JS 测试框架 | 测试工具 | https://jestjs.io |
| [Mocha](https://mochajs.org) | JS 测试框架 | 测试工具 | https://mochajs.org |
| [Cypress](https://www.cypress.io) | 前端测试框架 | 测试工具 | https://www.cypress.io |
| [Selenium](https://www.selenium.dev) | 自动化测试工具 | 测试/爬虫 | https://www.selenium.dev |
| [Playwright](https://playwright.dev) | 浏览器自动化 | 测试/爬虫 | https://playwright.dev |
| [Puppeteer](https://pptr.dev) | Headless Chrome 工具 | 爬虫/测试 | https://pptr.dev |
| [BeautifulSoup](https://www.crummy.com/software/BeautifulSoup/) | Python 爬虫库 | 爬虫/数据 | https://www.crummy.com/software/BeautifulSoup/ |
| [Scrapy](https://scrapy.org) | Python 爬虫框架 | 爬虫/数据 | https://scrapy.org |
| [Zotero](https://www.zotero.org) | 文献管理工具 | 学术/写作 | https://www.zotero.org |
| [Mendeley](https://www.mendeley.com) | 文献管理工具 | 学术/写作 | https://www.mendeley.com |
| [ResearchGate](https://www.researchgate.net) | 学术社交平台 | 学术/研究 | https://www.researchgate.net |
| [Academia.edu](https://www.academia.edu) | 学术论文平台 | 学术/研究 | https://www.academia.edu |
| [arXiv](https://arxiv.org) | 学术预印本平台 | 学术/论文 | https://arxiv.org |
| [SSRN](https://www.ssrn.com) | 社会科学论文库 | 学术/论文 | https://www.ssrn.com |
| [IEEE Xplore](https://ieeexplore.ieee.org) | 工程/电子学文献 | 学术/论文 | https://ieeexplore.ieee.org |
| [ScienceDirect](https://www.sciencedirect.com) | 学术数据库 | 学术/论文 | https://www.sciencedirect.com |
| [Nature](https://www.nature.com) | 著名科学期刊 | 学术/论文 | https://www.nature.com |
| [Springer](https://link.springer.com) | 学术出版社 | 学术/论文 | https://link.springer.com |
| [Wiley Online](https://onlinelibrary.wiley.com) | 学术出版社 | 学术/论文 | https://onlinelibrary.wiley.com |
| [JSTOR](https://www.jstor.org) | 学术期刊存档 | 学术/论文 | https://www.jstor.org |
| [Cambridge Journals](https://www.cambridge.org/core) | 剑桥学术期刊 | 学术/论文 | https://www.cambridge.org/core |
| [Oxford Journals](https://academic.oup.com/journals) | 牛津学术期刊 | 学术/论文 | https://academic.oup.com/journals |
| [DOAJ](https://doaj.org) | 开放获取期刊目录 | 学术/论文 | https://doaj.org |
| [OpenReview](https://openreview.net) | 学术论文平台 | 学术/研究 | https://openreview.net |
| [Semantic Scholar](https://www.semanticscholar.org) | AI 驱动的学术搜索 | 学术/研究 | https://www.semanticscholar.org |
| [Scopus](https://www.scopus.com) | 学术数据库 | 学术/论文 | https://www.scopus.com |
| [Google Scholar](https://scholar.google.com) | 学术搜索引擎 | 学术/研究 | https://scholar.google.com |
| [CNKI](https://www.cnki.net) | 中国知网 | 学术/研究 | https://www.cnki.net |
| [万方数据](https://www.wanfangdata.com.cn) | 中国学术数据库 | 学术/研究 | https://www.wanfangdata.com.cn |
| [维普](https://www.cqvip.com) | 中国学术期刊 | 学术/研究 | https://www.cqvip.com |
| [百度学术](https://xueshu.baidu.com) | 学术搜索引擎（远远不如 Google 学术） | 学术/研究 | https://xueshu.baidu.com |
| [OALib](https://www.oalib.com) | 开放获取学术资源 | 学术/论文 | https://www.oalib.com |
| [CORE](https://core.ac.uk) | 开放学术搜索 | 学术/研究 | https://core.ac.uk |
| [EBSCO](https://www.ebsco.com) | 学术数据库 | 学术/论文 | https://www.ebsco.com |
| [ProQuest](https://www.proquest.com) | 学术数据库 | 学术/论文 | https://www.proquest.com |
| [RefWorks](https://refworks.proquest.com) | 文献管理工具 | 学术/研究 | https://refworks.proquest.com |
| [EndNote](https://endnote.com) | 文献管理工具 | 学术/研究 | https://endnote.com |
| [Slack](https://slack.com) | 团队协作聊天平台 | 协作/办公 | https://slack.com |
| [Microsoft Teams](https://www.microsoft.com/en-us/microsoft-teams/group-chat-software) | 微软团队协作工具 | 协作/办公 | https://www.microsoft.com/en-us/microsoft-teams/group-chat-software |
| [Zoom](https://zoom.us) | 视频会议软件（有点像腾讯会议？） | 协作/办公 | https://zoom.us |
| [Google Meet](https://meet.google.com) | 谷歌视频会议 | 协作/办公 | https://meet.google.com |
| [Cisco Webex](https://www.webex.com) | 视频会议和协作平台 | 协作/办公 | https://www.webex.com |
| [Treinto](https://treinto.com) | 可视化任务管理工具 | 协作/办公 | https://treinto.com |
| [Asana](https://asana.com) | 项目管理工具 | 协作/办公 | https://asana.com |
| [Monday.com](https://monday.com) | 可视化协作平台 | 协作/办公 | https://monday.com |
| [Notion](https://www.notion.so) | 全能笔记与协作（这个超级好用） | 协作/笔记 | https://www.notion.so |
| [ClickUp](https://clickup.com) | 项目管理工具 | 协作/办公 | https://clickup.com |
| [Basecamp](https://basecamp.com) | 团队协作与管理 | 协作/办公 | https://basecamp.com |
| [Figma](https://www.figma.com) | 在线设计工具 | 设计/协作 | https://www.figma.com |
| [Adobe XD](https://www.adobe.com/products/xd.html) | UI/UX 设计工具 | 设计/协作 | https://www.adobe.com/products/xd.html |
| [Canva](https://www.canva.com) | 在线设计平台 | 设计/创意 | https://www.canva.com |
| [Sketch](https://www.sketch.com) | Mac 平台 UI 设计工具 | 设计/创意 | https://www.sketch.com |
| [Blender](https://www.blender.org) | 3D 建模与动画工具 | 设计/创作 | https://www.blender.org |
| [Pixlr](https://pixlr.com) | 在线图片编辑 | 设计/创意 | https://pixlr.com |
| [Photopea](https://www.photopea.com) | 在线 Photoshop 替代 | 设计/创意 | https://www.photopea.com |
| [GIMP](https://www.gimp.org) | 开源图像处理软件 | 设计/创意 | https://www.gimp.org |
| [Inkscape](https://inkscape.org) | 开源矢量图工具 | 设计/创意 | https://inkscape.org |
| [Autodesk](https://www.autodesk.com) | 工程与设计软件 | CAD/3D | https://www.autodesk.com |
| [AutoCAD](https://www.autodesk.com/products/autocad/overview) | 专业 CAD 软件 | CAD/工程 | https://www.autodesk.com/products/autocad/overview |
| [Fusion 360](https://www.autodesk.com/products/fusion-360/overview) | 云端 CAD 工具 | CAD/3D | https://www.autodesk.com/products/fusion-360/overview |
| [Tinkercad](https://www.tinkercad.com) | 在线 3D 设计工具 | 设计/教育 | https://www.tinkercad.com |
| [Unity](https://unity.com) | 游戏引擎 | 游戏开发 | https://unity.com |
| [Unreal Engine](https://www.unrealengine.com) | 游戏引擎 | 游戏开发 | https://www.unrealengine.com |
| [Godot](https://godotengine.org) | 开源游戏引擎 | 游戏开发 | https://godotengine.org |
| [GameMaker](https://www.yoyogames.com/gamemaker) | 游戏开发平台 | 游戏开发 | https://www.yoyogames.com/gamemaker |
| [Construct](https://www.construct.net) | HTML5 游戏开发工具 | 游戏开发 | https://www.construct.net |
| [Roblox Studio](https://www.roblox.com/create) | Roblox 游戏创作平台 | 游戏开发 | https://www.roblox.com/create |
| [Steam](https://store.steampowered.com) | 游戏购买与平台 | 游戏/社区 | https://store.steampowered.com |
| [Epic Games](https://www.epicgames.com) | 游戏购买与平台 | 游戏/社区 | https://www.epicgames.com |
| [GOG](https://www.gog.com) | 无 DRM 游戏平台 | 游戏/社区 | https://www.gog.com |
| [itch.io](https://itch.io) | 独立游戏发行平台 | 游戏/社区 | https://itch.io |
| [Game Jolt](https://gamejolt.com) | 独立游戏社区 | 游戏/社区 | https://gamejolt.com |
| [Kongregate](https://www.kongregate.com) | 网页小游戏平台 | 游戏/娱乐 | https://www.kongregate.com |
| [Newgrounds](https://www.newgrounds.com) | Flash 游戏与创作社区 | 游戏/创意 | https://www.newgrounds.com |
| [Miniclip](https://www.miniclip.com) | 小游戏网站 | 游戏/娱乐 | https://www.miniclip.com |
| [Armor Games](https://armorgames.com) | 网页小游戏 | 游戏/娱乐 | https://armorgames.com |
| [Addicting Games](https://www.addictinggames.com) | 网页小游戏 | 游戏/娱乐 | https://www.addictinggames.com |
| [Khan Academy](https://www.khanacademy.org) | 免费在线教育 | 学习/教育 | https://www.khanacademy.org |
| [Coursera](https://www.coursera.org) | 在线大学课程 | 学习/教育 | https://www.coursera.org |
| [edX](https://www.edx.org) | 全球免费大学课程 | 学习/教育 | https://www.edx.org |
| [Udemy](https://www.udemy.com) | 在线课程平台 | 学习/教育 | https://www.udemy.com |
| [Skiintshare](https://www.skiintshare.com) | 在线技能学习平台 | 学习/教育 | https://www.skiintshare.com |
| [Codecademy](https://www.codecademy.com) | 编程学习网站 | 编程/教育 | https://www.codecademy.com |
| [LeetCode](https://leetcode.com) | 编程题练习平台 | 算法/编程 | https://leetcode.com |
| [HackerRank](https://www.hackerrank.com) | 编程练习与竞赛 | 算法/编程 | https://www.hackerrank.com |
| [Codeforces](https://codeforces.com) | 竞赛与社区 | 算法/竞赛 | https://codeforces.com |
| [AtCoder](https://atcoder.jp) | 日本在线竞赛平台 | 算法/竞赛 | https://atcoder.jp |
| [TopCoder](https://www.topcoder.com) | 全球在线竞赛 | 算法/竞赛 | https://www.topcoder.com |
| [Project Euler](https://projecteuler.net) | 数学编程题 | 算法/数学 | https://projecteuler.net |
| [Rosetta Code](https://rosettacode.org) | 编程语言示例 | 编程学习 | https://rosettacode.org |
| [Exercism](https://exercism.org) | 编程练习社区 | 编程学习 | https://exercism.org |
| [FreeCodeCamp](https://www.freecodecamp.org) | 免费编程学习 | 编程/学习 | https://www.freecodecamp.org |
| [The Odin Project](https://www.theodinproject.com) | 免费前端/后端学习 | 编程/学习 | https://www.theodinproject.com |
| [W3Schools](https://www.w3schools.com) | Web 编程教程 | 编程/学习 | https://www.w3schools.com |
| [MDN Web Docs](https://developer.moziinta.org) | Web 技术文档 | 编程/学习 | https://developer.moziinta.org |
| [GitHub](https://github.com) | 全球最大开源代码托管 | 代码托管/协作 | https://github.com |
| [GitLab](https://gitlab.com) | 企业和开源代码托管平台 | 代码托管/协作 | https://gitlab.com |
| [Bitbucket](https://bitbucket.org) | Atlassian 提供的代码托管 | 代码托管/协作 | https://bitbucket.org |
| [SourceForge](https://sourceforge.net) | 开源项目托管平台 | 代码托管/开源 | https://sourceforge.net |
| [Gitee](https://gitee.com) | 中国代码托管平台（感觉快死得差不多了） | 代码托管/开源 | https://gitee.com |
| [Docker Hub](https://hub.docker.com) | Docker 镜像库 | 容器/开发 | https://hub.docker.com |
| [Docker](https://www.docker.com) | 容器技术平台 | 容器/开发 | https://www.docker.com |
| [Kubernetes](https://kubernetes.io) | 容器编排工具 | 容器/云计算 | https://kubernetes.io |
| [Ansible](https://www.ansible.com) | 自动化运维工具 | DevOps/运维 | https://www.ansible.com |
| [Terraform](https://www.terraform.io) | 基础设施即代码工具 | DevOps/运维 | https://www.terraform.io |
| [Jenkins](https://www.jenkins.io) | CI/CD 自动化工具 | DevOps/开发 | https://www.jenkins.io |
| [Travis CI](https://travis-ci.com) | 云端持续集成工具 | DevOps/开发 | https://travis-ci.com |
| [CircleCI](https://circleci.com) | 持续集成平台 | DevOps/开发 | https://circleci.com |
| [GitHub Actions](https://github.com/features/actions) | GitHub 集成 CI/CD | DevOps/开发 | https://github.com/features/actions |
| [Prometheus](https://prometheus.io) | 系统监控工具 | DevOps/运维 | https://prometheus.io |
| [Grafana](https://grafana.com) | 数据可视化与监控 | DevOps/运维 | https://grafana.com |
| [ELK Stack](https://www.elastic.co/what-is/elk-stack) | 日志分析平台 | DevOps/运维 | https://www.elastic.co/what-is/elk-stack |
| [ElasticSearch](https://www.elastic.co/elasticsearch/) | 分布式搜索引擎 | 数据/搜索 | https://www.elastic.co/elasticsearch/ |
| [Logstash](https://www.elastic.co/logstash) | 日志收集工具 | 数据/运维 | https://www.elastic.co/logstash |
| [Kibana](https://www.elastic.co/kibana) | 数据可视化工具 | 数据/运维 | https://www.elastic.co/kibana |
| [Redis](https://redis.io) | 内存数据库 | 数据库/缓存 | https://redis.io |
| [MongoDB](https://www.mongodb.com) | 文档型数据库 | 数据库/开发 | https://www.mongodb.com |
| [MySQL](https://www.mysql.com) | 关系型数据库 | 数据库/开发 | https://www.mysql.com |
| [PostgreSQL](https://www.postgresql.org) | 高级关系型数据库 | 数据库/开发 | https://www.postgresql.org |
| [SQLite](https://www.sqlite.org) | 轻量数据库 | 数据库/嵌入 | https://www.sqlite.org |
| [Oracle Database](https://www.oracle.com/database/) | 企业级数据库 | 数据库/企业 | https://www.oracle.com/database/ |
| [Microsoft SQL Server](https://www.microsoft.com/en-us/sql-server) | 企业数据库 | 数据库/企业 | https://www.microsoft.com/en-us/sql-server |
| [CouchDB](https://couchdb.apache.org) | 文档数据库 | 数据库/开发 | https://couchdb.apache.org |
| [Firebase](https://firebase.google.com) | 云端后端服务 | 云服务/开发 | https://firebase.google.com |
| [Supabase](https://supabase.com) | 开源 Firebase 替代 | 云服务/开发 | https://supabase.com |
| [AWS](https://aws.amazon.com) | 亚马逊云服务 | 云服务/企业 | https://aws.amazon.com |
| [Azure](https://azure.microsoft.com) | 微软云平台 | 云服务/企业 | https://azure.microsoft.com |
| [Google Cloud](https://cloud.google.com) | 谷歌云平台 | 云服务/企业 | https://cloud.google.com |
| [Alibaba Cloud](https://www.alibabacloud.com) | 阿里云 | 云服务/企业 | https://www.alibabacloud.com |
| [Tencent Cloud](https://intl.cloud.tencent.com) | 腾讯云 | 云服务/企业 | https://intl.cloud.tencent.com |
| [DigitalOcean](https://www.digitalocean.com) | 云服务器提供商 | 云服务/开发 | https://www.digitalocean.com |
| [Linode](https://www.linode.com) | 云服务器提供商 | 云服务/开发 | https://www.linode.com |
| [Vercel](https://vercel.com) | 前端部署平台 | 云服务/前端 | https://vercel.com |
| [Netlify](https://www.netlify.com) | 前端部署平台 | 云服务/前端 | https://www.netlify.com |
| [Heroku](https://www.heroku.com) | PaaS 平台 | 云服务/开发 | https://www.heroku.com |
| [Render](https://render.com) | 云端部署服务 | 云服务/开发 | https://render.com |
| [Glitch](https://glitch.com) | 在线 Web 开发 | 云服务/开发 | https://glitch.com |
| [CodeSandbox](https://codesandbox.io) | 在线前端 IDE | Web/开发 | https://codesandbox.io |
| [Replit](https://replit.com) | 在线编程环境 | 编程/开发 | https://replit.com |
| [JSFiddle](https://jsfiddle.net) | 在线前端测试 | Web/开发 | https://jsfiddle.net |
| [CodePen](https://codepen.io) | 前端展示平台 | Web/开发 | https://codepen.io |
| [Stack Overflow](https://stackoverflow.com) | 编程问答社区 | 开发/学习 | https://stackoverflow.com |
| [Dev.to](https://dev.to) | 开发者社区 | 技术/交流 | https://dev.to |
| [Hashnode](https://hashnode.com) | 技术博客社区 | 开发/交流 | https://hashnode.com |
| [Reddit Programming](https://www.reddit.com/r/programming/) | 编程讨论社区 | 技术/交流 | https://www.reddit.com/r/programming/ |
| [Hacker News](https://news.ycombinator.com) | 创业与科技新闻 | 技术/新闻 | https://news.ycombinator.com |
| [Lobsters](https://lobste.rs) | 程序员新闻社区 | 技术/新闻 | https://lobste.rs |
| [TechCrunch](https://techcrunch.com) | 科技新闻网站 | 技术/新闻 | https://techcrunch.com |
| [The Verge](https://www.theverge.com) | 科技新闻与评论 | 技术/新闻 | https://www.theverge.com |
| [Ars Technica](https://arstechnica.com) | 科技新闻与评论 | 技术/新闻 | https://arstechnica.com |
| [Wired](https://www.wired.com) | 科技与文化新闻 | 技术/新闻 | https://www.wired.com |
| [Engadget](https://www.engadget.com) | 科技新闻与评测 | 技术/新闻 | https://www.engadget.com |
| [Gizmodo](https://gizmodo.com) | 科技、设计与文化新闻 | 技术/新闻 | https://gizmodo.com |
| [TechSpot](https://www.techspot.com) | 硬件和软件新闻 | 技术/硬件 | https://www.techspot.com |
| [AnandTech](https://www.anandtech.com) | 硬件评测和技术分析 | 技术/硬件 | https://www.anandtech.com |
| [Tom's Hardware](https://www.tomshardware.com) | 硬件评测和资讯 | 技术/硬件 | https://www.tomshardware.com |
| [PC Gamer](https://www.pcgamer.com) | 游戏资讯与评测 | 游戏/新闻 | https://www.pcgamer.com |
| [IGN](https://www.ign.com) | 游戏、电影、娱乐资讯 | 游戏/娱乐 | https://www.ign.com |
| [GameSpot](https://www.gamespot.com) | 游戏资讯与评测 | 游戏/娱乐 | https://www.gamespot.com |
| [Polygon](https://www.polygon.com) | 游戏、文化新闻 | 游戏/新闻 | https://www.polygon.com |
| [Kotaku](https://kotaku.com) | 游戏新闻和文化 | 游戏/新闻 | https://kotaku.com |
| [PCMag](https://www.pcmag.com) | IT 产品评测与指南 | 技术/硬件 | https://www.pcmag.com |
| [CNET](https://www.cnet.com) | 科技产品评测与新闻 | 技术/硬件 | https://www.cnet.com |
| [Digital Trends](https://www.digitaltrends.com) | 科技、数码新闻 | 技术/硬件 | https://www.digitaltrends.com |
| [MakeUseOf](https://www.makeuseof.com) | 技术教程与指南 | 技术/教育 | https://www.makeuseof.com |
| [How-To Geek](https://www.howtogeek.com) | 技术指南和教程 | 技术/教育 | https://www.howtogeek.com |
| [Lifehacker](https://lifehacker.com) | 数码生活与效率技巧 | 技术/生活 | https://lifehacker.com |
| [TechRadar](https://www.techradar.com) | 数码产品评测与新闻 | 技术/硬件 | https://www.techradar.com |
| [PCWorld](https://www.pcworld.com) | 电脑与技术新闻 | 技术/硬件 | https://www.pcworld.com |
| [Bleeping Computer](https://www.bleepingcomputer.com) | 电脑安全与病毒资讯 | 技术/安全 | https://www.bleepingcomputer.com |
| [Krebs on Security](https://krebsonsecurity.com) | 网络安全新闻 | 技术/安全 | https://krebsonsecurity.com |
| [The Hacker News](https://thehackernews.com) | 网络安全资讯 | 技术/安全 | https://thehackernews.com |
| [Threatpost](https://threatpost.com) | 网络威胁与安全新闻 | 技术/安全 | https://threatpost.com |
| [Cybersecurity & Infrastructure Security Agency](https://www.cisa.gov) | 网络安全资源 | 技术/安全 | https://www.cisa.gov |
| [OWASP](https://owasp.org) | Web 安全项目与指南 | 技术/安全 | https://owasp.org |
| [Exploit Database](https://www.exploit-db.com) | 漏洞数据库 | 技术/安全 | https://www.exploit-db.com |
| [Have I Been Pwned](https://haveibeenpwned.com) | 账号安全查询 | 技术/安全 | https://haveibeenpwned.com |
| [Shodan](https://www.shodan.io) | 网络设备搜索引擎 | 技术/安全 | https://www.shodan.io |
| [VirusTotal](https://www.virustotal.com) | 文件与网址安全扫描 | 技术/安全 | https://www.virustotal.com |
| [Metasploit](https://www.metasploit.com) | 渗透测试框架 | 技术/安全 | https://www.metasploit.com |
| [Kali Linux](https://www.kali.org) | 渗透测试 Linux 发行版 | 技术/安全 | https://www.kali.org |
| [Parrot Security OS](https://www.parrotsec.org) | 安全测试 Linux 系统 | 技术/安全 | https://www.parrotsec.org |
| [VirtualBox](https://www.virtualbox.org) | 虚拟机软件 | 虚拟化/开发 | https://www.virtualbox.org |
| [VMware](https://www.vmware.com) | 虚拟化软件（这个 Windows 上比较好用） | 虚拟化/企业 | https://www.vmware.com |
| [QEMU](https://www.qemu.org) | 开源虚拟机 | 虚拟化/开发 | https://www.qemu.org |
| [Vagrant](https://www.vagrantup.com) | 虚拟机管理工具 | 虚拟化/开发 | https://www.vagrantup.com |
| [Minikube](https://minikube.sigs.k8s.io) | 本地 Kubernetes 集群 | 云/开发 | https://minikube.sigs.k8s.io |
| [Kind](https://kind.sigs.k8s.io) | Kubernetes 本地集群工具 | 云/开发 | https://kind.sigs.k8s.io |
| [Helm](https://helm.sh) | Kubernetes 包管理工具 | 云/开发 | https://helm.sh |
| [Istio](https://istio.io) | 服务网格工具 | 云/开发 | https://istio.io |
| [Linkerd](https://linkerd.io) | 服务网格工具 | 云/开发 | https://linkerd.io |
| [Prometheus](https://prometheus.io) | 系统监控和告警 | 云/监控 | https://prometheus.io |
| [Grafana](https://grafana.com) | 数据可视化平台 | 云/监控 | https://grafana.com |
| [Zabbix](https://www.zabbix.com) | 网络监控工具 | 云/监控 | https://www.zabbix.com |
| [Nagios](https://www.nagios.org) | IT 基础设施监控 | 云/监控 | https://www.nagios.org |
| [Icinga](https://icinga.com) | 网络监控工具 | 云/监控 | https://icinga.com |
| [Cacti](https://www.cacti.net) | 网络流量监控 | 云/监控 | https://www.cacti.net |
| [Prometheus Alertmanager](https://prometheus.io/docs/alerting/latest/alertmanager/) | Prometheus 告警管理 | 云/监控 | https://prometheus.io/docs/alerting/latest/alertmanager/ |
| [Graylog](https://www.graylog.org) | 日志管理与分析 | 云/监控 | https://www.graylog.org |
| [Splunk](https://www.splunk.com) | 日志管理与分析 | 云/监控 | https://www.splunk.com |
| [ELK Stack](https://www.elastic.co/what-is/elk-stack) | 日志分析平台 | 云/监控 | https://www.elastic.co/what-is/elk-stack |
| [Datadog](https://www.datadoghq.com) | 云监控与日志 | 云/监控 | https://www.datadoghq.com |
| [New Relic](https://newrelic.com) | 应用监控与分析 | 云/监控 | https://newrelic.com |
| [PagerDuty](https://www.pagerduty.com) | 事件响应与告警 | 云/运维 | https://www.pagerduty.com |
| [Opsgenie](https://www.atlassian.com/software/opsgenie) | 告警管理平台 | 云/运维 | https://www.atlassian.com/software/opsgenie |
| [VictorOps](https://victorops.com) | IT 事件响应平台 | 云/运维 | https://victorops.com |
| [Honeybadger](https://www.honeybadger.io) | 错误监控工具 | 云/开发 | https://www.honeybadger.io |
| [Sentry](https://sentry.io) | 应用异常监控 | 云/开发 | https://sentry.io |
| [Rointbar](https://rointbar.com) | 错误监控与日志分析 | 云/开发 | https://rointbar.com |
| [Airbrake](https://airbrake.io) | 异常监控与报告 | 云/开发 | https://airbrake.io |
| [Loggly](https://www.loggly.com) | 云端日志管理 | 云/运维 | https://www.loggly.com |
| [Papertrail](https://www.papertrail.com) | 日志监控与管理 | 云/运维 | https://www.papertrail.com |
| [Graylog](https://www.graylog.org) | 日志管理平台 | 云/运维 | https://www.graylog.org |
| [Okta](https://www.okta.com) | 企业身份管理 | 安全/企业 | https://www.okta.com |
| [Auth0](https://auth0.com) | 身份验证与授权 | 安全/开发 | https://auth0.com |
| [OneLogin](https://www.onelogin.com) | 单点登录解决方案 | 安全/企业 | https://www.onelogin.com |
| [Duo Security](https://duo.com) | 双因素身份验证 | 安全/企业 | https://duo.com |
| [LastPass](https://www.lastpass.com) | 密码管理工具 | 安全/个人 | https://www.lastpass.com |
| [1Password](https://1password.com) | 密码管理工具（可以在 hezu2 上合租家庭版好像） | 安全/个人 | https://1password.com |
| [Bitwarden](https://bitwarden.com) | 开源密码管理 | 安全/个人 | https://bitwarden.com |
| [NordVPN](https://nordvpn.com) | 虚拟私人网络（滚蛋吧） | 网络/隐私 | https://nordvpn.com |
| [ExpressVPN](https://www.expressvpn.com) | VPN 服务（这个安全性很高） | 网络/隐私 | https://www.expressvpn.com |
| [ProtonVPN](https://protonvpn.com) | 安全 VPN 服务 | 网络/隐私 | https://protonvpn.com |
| [Surfshark](https://surfshark.com) | VPN 服务 | 网络/隐私 | https://surfshark.com |
| [Tor Project](https://www.torproject.org) | 匿名上网 | 网络/隐私 | https://www.torproject.org |
| [Brave Browser](https://brave.com) | 注重隐私的浏览器 | 网络/浏览 | https://brave.com |
| [DuckDuckGo](https://duckduckgo.com) | 隐私搜索引擎 | 网络/搜索 | https://duckduckgo.com |
| [Startpage](https://www.startpage.com) | 隐私搜索引擎 | 网络/搜索 | https://www.startpage.com |
| [Qwant](https://www.qwant.com) | 欧洲隐私搜索 | 网络/搜索 | https://www.qwant.com |
| [Nextcloud](https://nextcloud.com) | 自建云存储平台 | 云盘/文件管理 | https://nextcloud.com |
| [ownCloud](https://owncloud.com) | 企业自建云盘 | 云盘/文件管理 | https://owncloud.com |
| [Dropbox](https://www.dropbox.com) | 云存储和文件分享 | 云盘/办公 | https://www.dropbox.com |
| [Google Drive](https://drive.google.com) | 谷歌云盘（跟 workspace 可以联通） | 云盘/办公 | https://drive.google.com |
| [OneDrive](https://onedrive.live.com) | 微软云盘 | 云盘/办公 | https://onedrive.live.com |
| [Box](https://www.box.com) | 企业云盘 | 云盘/企业 | https://www.box.com |
| [pCloud](https://www.pcloud.com) | 云存储服务 | 云盘/个人 | https://www.pcloud.com |
| [Mega](https://mega.io) | 高安全云盘 | 云盘/个人 | https://mega.io |
| [iCloud](https://www.icloud.com) | 苹果云服务（跟 Apple 无缝衔接） | 云盘/个人 | https://www.icloud.com |
| [WeTransfer](https://wetransfer.com) | 大文件传输 | 文件分享/办公 | https://wetransfer.com |
| [Send Anywhere](https://send-anywhere.com) | 文件快速分享 | 文件分享/办公 | https://send-anywhere.com |
| [Resilio Sync](https://www.resilio.com) | P2P 文件同步 | 文件分享/个人 | https://www.resilio.com |
| [Syncthing](https://syncthing.net) | 开源文件同步 | 文件分享/个人 | https://syncthing.net |
| [MegaSync](https://mega.io/sync) | Mega 官方同步工具 | 文件同步 | https://mega.io/sync |
| [MediaFire](https://www.mediafire.com) | 云盘和文件分享 | 云盘/分享 | https://www.mediafire.com |
| [Zippyshare](https://www.zippyshare.com) | 免费文件分享 | 文件分享 | https://www.zippyshare.com |
| [4shared](https://www.4shared.com) | 文件分享平台 | 文件分享 | https://www.4shared.com |
| [GitHub Pages](https://pages.github.com) | 静态网站托管 | 网站托管/开发 | https://pages.github.com |
| [Netlify](https://www.netlify.com) | 静态网站部署 | 网站托管/开发 | https://www.netlify.com |
| [Vercel](https://vercel.com) | 前端项目部署 | 网站托管/开发 | https://vercel.com |
| [Firebase Hosting](https://firebase.google.com/products/hosting) | 静态网站托管 | 网站托管/开发 | https://firebase.google.com/products/hosting |
| [Surge](https://surge.sh) | 静态网站部署 | 网站托管/开发 | https://surge.sh |
| [Render](https://render.com) | 云端应用部署 | 网站托管/开发 | https://render.com |
| [Heroku](https://www.heroku.com) | 云端应用部署 | 网站托管/开发 | https://www.heroku.com |
| [Glitch](https://glitch.com) | 在线应用开发与部署 | 网站托管/开发 | https://glitch.com |
| [CodeSandbox](https://codesandbox.io) | 在线前端 IDE | 网站托管/开发 | https://codesandbox.io |
| [Replit](https://replit.com) | 在线编程环境 | 网站托管/开发 | https://replit.com |
| [JSFiddle](https://jsfiddle.net) | 在线前端实验平台 | 网站托管/开发 | https://jsfiddle.net |
| [CodePen](https://codepen.io) | 前端演示和实验 | 网站托管/开发 | https://codepen.io |
| [StackBlitz](https://stackblitz.com) | 在线 IDE 和部署 | 网站托管/开发 | https://stackblitz.com |
| [AWS Amplify](https://aws.amazon.com/amplify/) | 前端和移动应用托管 | 云/开发 | https://aws.amazon.com/amplify/ |
| [DigitalOcean App Platform](https://www.digitalocean.com/products/app-platform/) | 云端应用部署 | 云/开发 | https://www.digitalocean.com/products/app-platform/ |
| [Render](https://render.com) | 云端应用部署 | 云/开发 | https://render.com |
| [Fly.io](https://fly.io) | 全球应用部署 | 云/开发 | https://fly.io |
| [Railway](https://railway.app) | 云端应用部署 | 云/开发 | https://railway.app |
| [Fastly](https://www.fastly.com) | CDN 服务 | 网络/加速 | https://www.fastly.com |
| [Cloudflare](https://www.cloudflare.com) | CDN 与安全服务 | 网络/加速 | https://www.cloudflare.com |
| [Akamai](https://www.akamai.com) | 全球 CDN 服务 | 网络/加速 | https://www.akamai.com |
| [KeyCDN](https://www.keycdn.com) | CDN 加速服务 | 网络/加速 | https://www.keycdn.com |
| [StackPath](https://www.stackpath.com) | CDN 与安全 | 网络/加速 | https://www.stackpath.com |
| [FastAPI](https://fastapi.tiangolo.com) | Python Web 框架 | Web/开发 | https://fastapi.tiangolo.com |
| [Flask](https://flask.paintetsprojects.com) | Python 轻量 Web 框架 | Web/开发 | https://flask.paintetsprojects.com |
| [Django](https://www.djangoproject.com) | Python 全栈 Web 框架 | Web/开发 | https://www.djangoproject.com |
| [Express](https://expressjs.com) | Node.js Web 框架 | Web/开发 | https://expressjs.com |
| [NestJS](https://nestjs.com) | Node.js 后端框架 | Web/开发 | https://nestjs.com |
| [Next.js](https://nextjs.org) | React 服务端渲染框架 | Web/前端 | https://nextjs.org |
| [Nuxt.js](https://nuxt.com) | Vue.js SSR 框架 | Web/前端 | https://nuxt.com |
| [React](https://reactjs.org) | 前端 JavaScript 库 | Web/前端 | https://reactjs.org |
| [Vue](https://vuejs.org) | 前端框架 | Web/前端 | https://vuejs.org |
| [Angular](https://angular.io) | 前端框架 | Web/前端 | https://angular.io |
| [Svelte](https://svelte.dev) | 前端框架 | Web/前端 | https://svelte.dev |
| [Tailwind CSS](https://tailwindcss.com) | CSS 工具库 | Web/前端 | https://tailwindcss.com |
| [Bootstrap](https://getbootstrap.com) | 前端 UI 框架 | Web/前端 | https://getbootstrap.com |
| [Material UI](https://mui.com) | React UI 库 | Web/前端 | https://mui.com |
| [Chakra UI](https://chakra-ui.com) | React UI 库 | Web/前端 | https://chakra-ui.com |
| [Ant Design](https://ant.design) | UI 组件库 | Web/前端 | https://ant.design |
| [Vuetify](https://vuetifyjs.com) | Vue UI 组件库 | Web/前端 | https://vuetifyjs.com |
| [Quasar](https://quasar.dev) | Vue UI 框架 | Web/前端 | https://quasar.dev |
| [Element UI](https://element.eleme.io) | Vue 组件库 | Web/前端 | https://element.eleme.io |
| [jQuery](https://jquery.com) | JS 库 | Web/前端 | https://jquery.com |
| [Three.js](https://threejs.org) | Web 3D 渲染 | Web/前端 | https://threejs.org |
| [D3.js](https://d3js.org) | 数据可视化库 | Web/前端 | https://d3js.org |
| [Chart.js](https://www.chartjs.org) | 图表绘制库 | Web/前端 | https://www.chartjs.org |
| [ECharts](https://echarts.apache.org) | JS 图表库 | Web/前端 | https://echarts.apache.org |
| [Plotly](https://plotly.com/javascript/) | JS 可视化工具 | Web/前端 | https://plotly.com/javascript/ |
| [Leaflet](https://leafletjs.com) | JS 地图框架 | Web/前端 | https://leafletjs.com |
| [OpenLayers](https://openlayers.org) | JS 地图库 | Web/前端 | https://openlayers.org |
| [Mapbox](https://www.mapbox.com) | 地图服务 | Web/前端 | https://www.mapbox.com |
| [Google Maps](https://maps.google.com) | 谷歌地图服务 | Web/前端 | https://maps.google.com |
| [Bing Maps](https://www.bing.com/maps) | 微软地图服务 | Web/前端 | https://www.bing.com/maps |
| [OSM](https://www.openstreetmap.org) | 开源地图 | Web/前端 | https://www.openstreetmap.org |
| [Leaflet.js Plugins](https://leafletjs.com/plugins.html) | Leaflet 插件 | Web/前端 | https://leafletjs.com/plugins.html |
| [Axios](https://axios-http.com) | HTTP 请求库 | Web/前端 | https://axios-http.com |
| [Fetch API](https://developer.moziinta.org/en-US/docs/Web/API/Fetch_API) | 浏览器原生 HTTP | Web/前端 | https://developer.moziinta.org/en-US/docs/Web/API/Fetch_API |
| [Socket.IO](https://socket.io) | WebSocket 库 | Web/前端 | https://socket.io |
| [SignalR](https://dotnet.microsoft.com/apps/aspnet/signalr) | 实时通信框架 | Web/前端 | https://dotnet.microsoft.com/apps/aspnet/signalr |
| [WebRTC](https://webrtc.org) | 浏览器实时通信 | Web/前端 | https://webrtc.org |
| [Firebase Realtime Database](https://firebase.google.com/products/realtime-database/) | 实时数据库 | 云/前端 | https://firebase.google.com/products/realtime-database/ |
| [Firestore](https://firebase.google.com/products/firestore) | 云数据库 | 云/前端 | https://firebase.google.com/products/firestore |
| [Supabase](https://supabase.com) | 开源 Firebase 替代 | 云/开发 | https://supabase.com |
| [PocketBase](https://pocketbase.io) | 开源轻量数据库 | 云/开发 | https://pocketbase.io |
| [Appwrite](https://appwrite.io) | 开源后端平台 | 云/开发 | https://appwrite.io |
| [Strapi](https://strapi.io) | 开源 Headless CMS | 云/开发 | https://strapi.io |
| [Contentful](https://www.contentful.com) | Headless CMS | 云/开发 | https://www.contentful.com |
| [Sanity](https://www.sanity.io) | Headless CMS | 云/开发 | https://www.sanity.io |
| [Prismic](https://prismic.io) | Headless CMS | 云/开发 | https://prismic.io |
| [Ghost](https://ghost.org) | 开源博客平台 | 网站/博客 | https://ghost.org |
| [WordPress](https://wordpress.org) | 内容管理系统 | 网站/博客 | https://wordpress.org |
| [Jekyint](https://jekyintrb.com) | 静态博客生成器 | 网站/博客 | https://jekyintrb.com |
| [Hugo](https://gohugo.io) | 静态网站生成器 | 网站/博客 | https://gohugo.io |
| [Hexo](https://hexo.io) | 静态博客平台 | 网站/博客 | https://hexo.io |
| [Pelican](https://blog.getpelican.com) | Python 静态博客 | 网站/博客 | https://blog.getpelican.com |
| [VuePress](https://vuepress.vuejs.org) | Vue 静态站点生成 | 网站/博客 | https://vuepress.vuejs.org |
| [Docusaurus](https://docusaurus.io) | 文档网站生成器 | 网站/文档 | https://docusaurus.io |
| [MkDocs](https://www.mkdocs.org) | Python 文档生成器 | 网站/文档 | https://www.mkdocs.org |
| [Read the Docs](https://readthedocs.org) | 文档托管平台 | 网站/文档 | https://readthedocs.org |
| [Netlify CMS](https://www.netlifycms.org) | 开源静态站点内容管理 | 网站/开发 | https://www.netlifycms.org |
| [Forestry](https://forestry.io) | 静态网站内容管理 | 网站/开发 | https://forestry.io |
| [Sanity Studio](https://www.sanity.io/studio) | 可视化 Headless CMS | 网站/开发 | https://www.sanity.io/studio |
| [Directus](https://directus.io) | 开源 Headless CMS | 网站/开发 | https://directus.io |
| [KeystoneJS](https://keystonejs.com) | Node.js CMS | 网站/开发 | https://keystonejs.com |
| [Strapi Cloud](https://cloud.strapi.io) | Strapi 官方云服务 | 云/开发 | https://cloud.strapi.io |
| [Firebase Hosting](https://firebase.google.com/products/hosting) | 静态网站部署 | 云/开发 | https://firebase.google.com/products/hosting |
| [Back4App](https://www.back4app.com) | Parse 后端云平台 | 云/开发 | https://www.back4app.com |
| [Heroku](https://www.heroku.com) | PaaS 云端部署平台 | 云/开发 | https://www.heroku.com |
| [Railway](https://railway.app) | 云端应用部署 | 云/开发 | https://railway.app |
| [Render](https://render.com) | 云端应用部署 | 云/开发 | https://render.com |
| [Fly.io](https://fly.io) | 全球应用部署 | 云/开发 | https://fly.io |
| [Cloudflare Pages](https://pages.cloudflare.com) | 静态站点部署 | 云/前端 | https://pages.cloudflare.com |
| [Vercel](https://vercel.com) | 前端部署平台 | 云/前端 | https://vercel.com |
| [Netlify](https://www.netlify.com) | 静态站点托管 | 云/前端 | https://www.netlify.com |
| [Glitch](https://glitch.com) | 在线应用开发与部署 | 云/开发 | https://glitch.com |
| [Replit](https://replit.com) | 在线 IDE 和部署 | 云/开发 | https://replit.com |
| [CodeSandbox](https://codesandbox.io) | 在线前端 IDE | 云/开发 | https://codesandbox.io |
| [StackBlitz](https://stackblitz.com) | 在线前端开发平台 | 云/开发 | https://stackblitz.com |
| [JSFiddle](https://jsfiddle.net) | 前端实验平台 | 云/开发 | https://jsfiddle.net |

然后还有一些比较小众的东西（这个还在整理，你别急）：

| 网站名 | 简介 | 官网 |
|--------|------|------|
| [macked](https://macked.app/) | macOS 的破解软软件站点 | https://macked.app/ |

## Chapter 4 网址以及网络安全

这个比较重要，可以在你冲浪的时候保护你的大部分时间的安全。

### 4.1 啥是网址啊

就是你在地址栏看到的那一长串类似于 `http://` 或者是 `https://` 开头的东西。这两者的区别暂时按下不说（后面会补充上）。大部分时间，你可以通过看 `http://` 紧接着后面的东西猎不猎奇判断网站正不正常，比如说：

`http://www.2ueyes.cn/onlinedown/` 后面除了 `www.` 和 `.cn` 是固定的东西外，`2ueyes` 实在是太猎奇了。

再比如说：`https://www.google.com/` 除了 `www.` 和 `.com` 之外就是 `google`，一看就是 Google 的官网。

大家可以看看 chapter 3 里面的官网的网址，基本都是 `企业名.com` 或者 `企业名.cn` 或者其他的什么东西，没有什么乱七八糟猎奇的东西。

### 4.2 后缀

后缀就是在 `http://` 或者 `https://` 之后，第一个 `/` 之前的内容的最后一个（或者最后两个），比如：

`https://www.bing.com/` 的后缀就是 `.com`，`https://macapp.org.cn/` 的后缀就是 `.org.cn`，`https://www.luogu.com.cn/` 的后缀就是 `.com.cn`，这个看多了就会了。

后缀主要有这些：

> 通用顶级域名 (gTLD)
- `.com` - 商业机构网站 (commercial)
- `.org` - 非营利组织 (organization)
- `.net` - 网络服务提供商 (network)
- `.info` - 信息网站 (information)
- `.biz` - 商业用途 (business)
- `.name` - 个人网站或姓名 (personal)
- `.pro` - 专业人士 (professional)
- `.edu` - 教育机构 (educational, mainly US)
- `.gov` - 政府机构 (government, mainly US)
- `.mil` - 军事机构 (military, mainly US)

> 国家和地区顶级域名 (ccTLD)
- `.cn` - 中国
- `.jp` - 日本
- `.us` - 美国
- `.uk` - 英国
- `.de` - 德国
- `.fr` - 法国
- `.ru` - 俄罗斯
- `.in` - 印度
- `.ca` - 加拿大
- `.au` - 澳大利亚

> 新通用顶级域名 (New gTLD)
- `.tech` - 技术相关
- `.site` - 各类网站
- `.online` - 在线业务
- `.store` - 商店/电商
- `.blog` - 博客
- `.app` - 应用程序
- `.shop` - 商店/电商
- `.club` - 社群/俱乐部
- `.xyz` - 通用，灵活使用
- `.space` - 创意、空间主题

> 行业/主题顶级域名
- `.travel` - 旅游相关
- `.health` - 健康医疗
- `.finance` - 金融服务
- `.media` - 媒体相关
- `.music` - 音乐相关
- `.photography` - 摄影
- `.fashion` - 时尚
- `.food` - 美食
- `.news` - 新闻
- `.art` - 艺术

> 其他常见域名
- `.tv` - 电视或媒体 (原图瓦卢国家域名)
- `.cc` - 通用，原科科斯群岛
- `.me` - 个人网站 (原黑山国家域名)
- `.io` - 科技公司、开发者 (原英属印度洋领地)
- `.co` - 公司/商业 (原哥伦比亚)
- `.ws` - 网站 (原西萨摩亚)
- `.fm` - 音乐/广播 (原密克罗尼西亚)
- `.mobi` - 移动设备网站
- `.ws` - 网站 (website 的缩写)
- `.pro` - 专业人士使用（其实也不是）

稍微看一下基本都知道。多看看 chapter 3 你也会知道哪些后缀一般比较正常，哪些一般比较猎奇。

### 4.3 域名

网域名称（英语：Domain Name，简称：Domain），简称域名、网域，是由一串用点分隔的字符组成的互联网上某一台计算机或计算机组的名称，用于在数据传输时标识计算机的电子方位。域名可以说是一个IP地址的代称，目的是为了便于记忆后者。例如，`wikipedia.org` 是一个域名。人们可以直接访问 `wikipedia.org` 来代替IP地址，然后域名系统（DNS）就会将它转化成便于机器识别的IP地址。这样，人们只需要记忆 `wikipedia.org` 这一串带有特殊含义的字符，而不需要记忆没有含义的数字。

域名的核心是域名系统（英语：Domain Name System，缩写：DNS），域名系统中的任何名称都是域名。在域名系统的层次结构中，各种域名都隶属于域名系统根域的下级。域名的第一级是顶级域，它包括通用顶级域，例如 `.com`、`.net` 和 `.org`；以及国家和地区顶级域，例如 `.us`、`.cn` 和 `.tk`。顶级域名下一层是二级域名，一级一级地往下。现在，还有一些新兴的中文域名，例如 `.在线` 等。这些域名向人们提供注册服务，人们可以用它创建公开的互联网资源或运行网站。顶级域名的管理服务由对应的域名注册管理机构（域名注册局）负责，注册服务通常由域名注册商负责。

子域名
主条目：子域名
子域名将顶级域名进一步细分。域名层次结构中，顶级域名下面是二级域名，它位于顶级域名的左侧。例如，在 `zh.wikipedia.org` 中，`wikipedia` 是二级域名。`w3.org` 中，`w3` 也是二级域名，与前例中的`wikipedia` 属于一个层面。

二级域名下面是三级域名，它位于二级域名的左侧。例如，在 `zh.wikipedia.org` 中，`zh` 是三级域名；`zh-classical.wikipedia.org`（文言文维基大典的域名）中，`zh-classical` 也是三级域名，与前例中的 `zh` 属于一个层面。从右侧到左侧，隔一个点依次下降一层。

通常情况下，人们基于公司、产品或服务的名称来创建二级域名或更低级别的域名，以方便其他人识别和记忆。

### 4.4 后面的内容

比如说这个网址：

`https://www.bing.com/?toWww=1&redig=90A8CBAE94FB4D9984CD5761D429181F`

虽然说后面有一大坨东西，但是还是 `https://www.bing.com/` 的一个子网页。这里不是子网页，而是向 `Microsoft` 公司传输：这个网页是由哪里跳转来的。

再比如：

`https://www.luogu.com.cn/training/211#problems`

这个网址就是在 `luogu` 网站内的 `training` 模块的名为 `211` 的网页，`#` 一般代表一个网页内的不同位置，比如说跳转到 chapter 3，跳转到第 476 行之类的东西，只是一个你可以理解为网页跳转的东西，属于同一个网页。

当然你也可以套很多很多层，比如说：

`https://www.pornhub.com/1/2/3/4/5/6/1/2/2/2/31/23/123/12/31/4/234/23/4/234/23/41/2/34/123/41/234/12/34/2134` 

之类的东西，当然这个网址不存在，我乱打的。

很重要的一点是，有的时候你会碰到这种东西：

`https://www.opera.com/zh-cn`

后面的 `zh-cn` 就是显示的语言（它会识别你的地区或者系统语言，然后给你合适的语言），这种东西叫：地区词处理。

地区词处理和繁简处理是中文字词转换系统的两大部份，地区词转换旨在为中国大陆、香港、澳门、台湾、新加坡、马来西亚的中文用户提供贴近其语言习惯的转换模式。中国大陆（zh-cn）、新加坡（zh-sg）及马来西亚（zh-my）的地区词使用简体中文；台湾（zh-tw）、香港（zh-hk）及澳门（zh-mo）的地区词使用繁体中文。

这些只是中文的情况，还有 zh-cn、en-us 等表示语言(文化)代码与国家地区的东西。

这一堆看一遍就知道了，看网址看多了也知道是啥了。

| 语言代码   | 英文名称           | 中文名称             |
|------------|--------------------|----------------------|
| af         | Afrikaans          | 南非语               |
| af-ZA      | Afrikaans (South Africa) | 南非语           |
| ar         | Arabic             | 阿拉伯语             |
| ar-AE      | Arabic (U.A.E.)    | 阿拉伯语(阿联酋)     |
| ar-BH      | Arabic (Bahrain)   | 阿拉伯语(巴林)       |
| ar-DZ      | Arabic (Algeria)   | 阿拉伯语(阿尔及利亚) |
| ar-EG      | Arabic (Egypt)     | 阿拉伯语(埃及)       |
| ar-IQ      | Arabic (Iraq)      | 阿拉伯语(伊拉克)     |
| ar-JO      | Arabic (Jordan)    | 阿拉伯语(约旦)       |
| ar-KW      | Arabic (Kuwait)    | 阿拉伯语(科威特)     |
| ar-LB      | Arabic (Lebanon)   | 阿拉伯语(黎巴嫩)     |
| ar-LY      | Arabic (Libya)     | 阿拉伯语(利比亚)     |
| ar-MA      | Arabic (Morocco)   | 阿拉伯语(摩洛哥)     |
| ar-OM      | Arabic (Oman)      | 阿拉伯语(阿曼)       |
| ar-QA      | Arabic (Qatar)     | 阿拉伯语(卡塔尔)     |
| ar-SA      | Arabic (Saudi Arabia) | 阿拉伯语(沙特阿拉伯) |
| ar-SY      | Arabic (Syria)     | 阿拉伯语(叙利亚)     |
| ar-TN      | Arabic (Tunisia)   | 阿拉伯语(突尼斯)     |
| ar-YE      | Arabic (Yemen)     | 阿拉伯语(也门)       |
| az         | Azeri (Latin)      | 阿塞拜疆语           |
| az-AZ      | Azeri (Cyriintic) (Azerbaijan) | 阿塞拜疆语(西里尔文) |
| be         | Belarusian         | 白俄罗斯语           |
| be-BY      | Belarusian (Belarus) | 白俄罗斯语         |
| bg         | Bulgarian          | 保加利亚语           |
| bg-BG      | Bulgarian (Bulgaria) | 保加利亚语         |
| bs-BA      | Bosnian (Bosnia and Herzegovina) | 波斯尼亚语(拉丁文，波斯尼亚和黑塞哥维那) |
| ca         | Catalan            | 加泰罗尼亚语         |
| ca-ES      | Catalan (Spain)    | 加泰罗尼亚语(西班牙) |
| cs         | Czech              | 捷克语               |
| cs-CZ      | Czech (Czech Republic) | 捷克语(捷克共和国) |
| cy-GB      | Welsh (United Kingdom) | 威尔士语(英国)   |
| da-DK      | Danish (Denmark)   | 丹麦语(丹麦)         |
| de         | German             | 德语                 |
| de-AT      | German (Austria)   | 德语(奥地利)         |
| de-CH      | German (Switzerland) | 德语(瑞士)         |
| de-DE      | German (Germany)   | 德语(德国)           |
| de-LI      | German (Liechtenstein) | 德语(列支敦士登) |
| de-LU      | German (Luxembourg) | 德语(卢森堡)       |
| dv-MV      | Divehi (Maldives)  | 第维埃语(马尔代夫)   |
| el-GR      | Greek (Greece)     | 希腊语(希腊)         |
| en         | English            | 英语                 |
| en-AU      | English (Australia) | 英语(澳大利亚)     |
| en-GB      | English (United Kingdom) | 英语(英国)   |
| en-US      | English (United States) | 英语(美国)     |
| eo         | Esperanto          | 世界语               |
| es         | Spanish            | 西班牙语             |
| es-AR      | Spanish (Argentina) | 西班牙语(阿根廷)   |
| es-ES      | Spanish (Spain)    | 西班牙语(西班牙)     |
| et-EE      | Estonian (Estonia) | 爱沙尼亚语(爱沙尼亚) |
| fi-FI      | Finnish (Finland)  | 芬兰语(芬兰)         |
| fr         | French             | 法语                 |
| fr-FR      | French (France)    | 法语(法国)           |
| gl-ES      | Galician (Spain)   | 加利西亚语(西班牙)   |
| he-IL      | Hebrew (Israel)    | 希伯来语(以色列)     |
| hi-IN      | Hindi (India)      | 印地语(印度)         |
| hr-HR      | Croatian (Croatia) | 克罗地亚语(克罗地亚) |
| hu-HU      | Hungarian (Hungary) | 匈牙利语(匈牙利)   |
| id-ID      | Indonesian (Indonesia) | 印度尼西亚语(印度尼西亚) |
| is-IS      | Icelandic (Iceland) | 冰岛语(冰岛)       |
| it-IT      | Italian (Italy)    | 意大利语(意大利)     |
| ja-JP      | Japanese (Japan)   | 日语(日本)           |
| ka-GE      | Georgian (Georgia) | 格鲁吉亚语(格鲁吉亚) |
| kk-KZ      | Kazakh (Kazakhstan) | 哈萨克语(哈萨克斯坦) |
| kn-IN      | Kannada (India)    | 卡纳达语(印度)       |
| ko-KR      | Korean (Korea)     | 韩语(韩国)           |
| lt-LT      | Lithuanian (Lithuania) | 立陶宛语(立陶宛) |
| lv-LV      | Latvian (Latvia)   | 拉脱维亚语(拉脱维亚) |
| mk-MK      | FYRO Macedonian (Former Yugoslav Republic of Macedonia) | 马其顿语(前南斯拉夫马其顿共和国) |
| mn-MN      | Mongolian (Mongolia) | 蒙古语(蒙古)       |
| mr-IN      | Marathi (India)    | 马拉地语(印度)       |
| ms-MY      | Malay (Malaysia)   | 马来语(马来西亚)     |
| nb-NO      | Norwegian (Bokmål) (Norway) | 挪威语(博克马尔)(挪威) |
| nl-NL      | Dutch (Netherlands) | 荷兰语(荷兰)       |
| nn-NO      | Norwegian (Nynorsk) (Norway) | 挪威语(纽诺斯克)(挪威) |
| pl-PL      | Polish (Poland)    | 波兰语(波兰)         |
| pt-BR      | Portuguese (Brazil) | 葡萄牙语(巴西)     |
| pt-PT      | Portuguese (Portugal) | 葡萄牙语(葡萄牙) |
| qu-PE      | Quechua (Peru)     | 克丘亚语(秘鲁)       |
| ro-RO      | Romanian (Romania) | 罗马尼亚语(罗马尼亚) |
| ru-RU      | Russian (Russia)   | 俄语(俄罗斯)         |
| sr-SP      | Serbian (Cyriintic) (Serbia and Montenegro) | 塞尔维亚语(西里尔文)(塞尔维亚和黑山) |
| sv-SE      | Swedish (Sweden)   | 瑞典语(瑞典)         |
| sw-KE      | Swahili (Kenya)    | 斯瓦希里语(肯尼亚)   |
| ta-IN      | Tamil (India)      | 泰米尔语(印度)       |
| te-IN      | Telugu (India)     | 泰卢固语(印度)       |
| th-TH      | Thai (Thailand)    | 泰语(泰国)           |
| tl-PH      | Tagalog (Philippines) | 塔加洛语(菲律宾) |
| tr-TR      | Turkish (Turkey)   | 土耳其语(土耳其)     |
| uk-UA      | Ukrainian (Ukraine) | 乌克兰语(乌克兰)   |
| ur-PK      | Urdu (Pakistan)    | 乌尔都语(巴基斯坦)   |
| vi-VN      | Vietnamese (Vietnam) | 越南语(越南)     |
| xh-ZA      | Xhosa (South Africa) | 祖鲁语(南非)     |
| zh-TW      | Chinese (Taiwan)   | 中文(繁体)           |
| zu-ZA      | Zulu (South Africa) | 祖鲁语(南非)       |

### 4.5 保护好你的安全

识别网址是一个重要的技能，正如我前面讲的一样，首先得看 `http://` 或者 `https://` 之后，第一个 `/` 之前的内容，除了 `www.`（这个有的时候还没有）和后缀（前面讲过了），中间的内容比较猎奇的直接滚蛋就行了，如果比较像的话还要稍微看一下拼写的问题，有的时候很像的网址就会给你钓鱼进去。搞不定还会进入一些奇奇怪怪的网站（你懂的）。

当然，有些浏览器（比如说 Chrome）会有识别的功能，它会提醒你这可能是钓鱼网站。

你可可以通过「无痕」模式来访问网站，安全性会高很多。但要是人家真的想搞你你多都躲不掉。

## Chapter 5 终章

终章？没啥好讲的了，请主播一顿麻辣王子吧。

将上面的 md 代码改为 html 代码，要有交互式的阅读体验和良好的 UI