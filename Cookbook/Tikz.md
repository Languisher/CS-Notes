# Tikz

查看完整版本，请在 cmd 输入 `texdoc tikz`，本文仅是简略版本。

## 基本图形对象

### 基础用法

`\draw[option]...;`

以下代码实例中省略了 `\draw` 部分。

- 直线：
    - 点坐标--点坐标 `(1,3)--(2,5)--(4,5)`
    - 节点名称--节点名称 `(n1)--(n2)`
    - 圆角转角：`[rounded corners]`
    
- 封闭图形：点坐标-cycle `(...)-cycle`
- 矩形：一对对角顶点 `(0,0) rectangle (4,2)`
- 圆、椭圆、弧 
    - 圆：圆心+半径 `(0,0) circle (2)`
    - 椭圆：重心+（长轴长 and 短轴长） `(1,1) ellipse (2 and 1)`
    - 圆弧：圆心+（起始角度：结束角度：半径） `(1,1) arc (0:270:1)`
    - 椭圆弧：重心+（起始角度：结束角度：长轴长 and 短轴长） `(6,1) arc (0:270:2 and 1)`
- 弧线
    - 曲线：起点+顶点+终点 `(5,1) parabola bend (6,0) (7,414,2)`
- 网格
    - 起点+终点 `(0,0) grid (3,2)`
        - 步长 `[step=20pt]`
        - 网格用 0.2pt 的灰线：`[help lines, step=20pt]`

```latex
\draw (1,3)--(2,2)--(4,5);
\draw[rounded corners] (1,3)--(2,2)--(4,5);
\draw (1,3)--(2,2)--(4,5)--cycle;
\draw (0,0) rectangle (4,2);
\draw (1,1) circle (1);
\draw (1,1) ellipse (2 and 1);
\draw (6 ,1) arc (0:270:2 and 1);
\draw [step=20pt] (0,0) grid (3,2);
\draw [help lines ,step=20pt] (4,0) grid (7,2);
```

### 填充图形 filldraw

- 标记**点**、绘制圆：
    - 圆心或点坐标+半径 `\filldraw (5,1) circle (.1)`
    - 多个点之间用换行隔开

```latex
\filldraw (5,1) circle (.1)
(6,0) circle (.1)
(7.414 ,2) circle (.1);
```

### 箭头

- `[option]` 中可以需要添加 `|`, `<>`, `-` 要素
- 起始点+终止点：`(0,0)--(9,0)`

```latex
\draw [->] (0,0)--(9,0);
\draw [<-] (0,1)--(9,1);
\draw [<->] (0,2)--(9,2);
\draw [>->>] (0,3)--(9,3);
\draw [|<->|] (0,4)--(9,4);
```

### 图形变换

默认在 `[option]` 处修改。

- 平移
    - `[shift={(3,0)}]`
    - `[xshift=100pt, yshift=-50pt]`
- 缩放
    - 指定**水平/竖直方向缩放**$a$**倍**。若$a>1$则代表水平方向放大（水平拉长）；若$a<1$则代表水平方向缩小（水平缩短）：`[xscale=a, yscale=a]`
    - 整体缩放：`scale=1.5`
- 旋转
    - 根据起点旋转，正数表示**逆时针旋转**：`[rotate=45] `
    - 根据定点旋转：`[rotate around={45:(2,2)}]`
- 倾斜
    - `[xslant=1]`

## 图形控制

### 线型和线宽

`[option]` 中设置：

- 线宽
    - 默认线宽：`[ultra thick], [thick], [thin]`
    - 指定线宽（默认 0.4pt）：`[line width=2pt]`

- 线状/点状虚线：`[dashed]` 或 `[dotted]`
- 较密或较疏：`[densely]` 或 `[loosely]`

```latex
\draw [line width =2pt] (0,0)--(9,0); %加粗实线
\draw [dotted] (0,1)--(9,1); %点状虚线
\draw [densely dotted] (0,2)--(9,2); %较密的点状虚线
\draw [loosely dotted] (0,3)--(9,3); %较疏的点状虚线
\draw [dashed] (0,4)--(9,4); %线状虚线
\draw [densely dashed] (0,5)--(9,5); %较密的线状虚线
\draw [loosely dashed] (0,6)--(9,6); %较疏的线状虚线
```

### 颜色和填充

- `\draw` : `[option]` 中指定颜色：`[red]`
- `\filldraw`: `[option]` 中分别指定**封闭图形**的边界和内部填充的颜色：`[draw=red, fill=blue]`

```latex
\draw[red] (0,0) --(9,0);
\draw[green] (0,1) --(9,1);
\draw[blue] (0,2) --(9,2);
\filldraw[draw=blue!80,fill=blue!20] (14 ,1) circle (1);
```

## 节点与标签

### 基本图形

- 文本框：位置+内容：`\node at (pos1, pos2) {text};`

    - 常规坐标系
    - 极坐标系：$\theta$+$r$：`(4*72:2)`

- 带框文本框：【框形状】+内容+【标签文本】+内容：`\node [draw, circle] at (pos1, pos2) [label={text1}] {text2}`

- 带框带底色文本框：【框形状+填充颜色】+内容+【标签文本】+内容：`\node[draw,diamond,fill=red!50] at (1,1) {yes};`

- 标签：【相对位置】+位置+内容：

    ```latex
    \node [below right] at (1,0) {$x$};
    \node[above right] at (.4,.6) {$A$};
    ```

```latex
\node (v5) at (4*72:2) {$v_5$};
\node (v1) at ( 0:3) [label=below:$v_1$] {};
```



### 自定义格式

边框形状，圆或方角，最小宽度，最小高度，文字和边框距离，边框和填充颜色

```latex
%本部分已内置模版中
\tikzset{
box/.style ={
rectangle, %矩形节点
rounded corners =5pt, %圆角
minimum width =50pt, %最小宽度
minimum height =20pt, %最小高度
inner sep=5pt, %文字和边框的距离
draw=blue %边框颜色}
}
```

## 复合图形对象

### 流程图实例

- 画节点：节点样式+节点名称+节点位置+节点内填充文本：`\node[option] (name-of-the-box) at (pos1, pos2) {text-in-the-box}`
    - `[option]` 中可以填入自定义样式（默认是无边框），例如 `[box]`, `[circle,
        minimum width =30pt ,
        minimum height =30pt ,draw=blue]`
- 用箭头连接

### 树实例

- 画孩子：指定子节点样式+子节点名称： `child {node[option] {node_name}}`
- 画多个孩子：同级孩子之间换行见实例
- 可以在开头指定族间距离：`[sibling distance = 80pt]`

```latex
\node[box] {1}
    child {node[box] {2}}
    child {node[box] {3}
        child {node[box] {4}}
        child {node[box] {5}}
        child {node[box] {6}}
    };
```

## 函数图形

### 横纵轴

见示例。可以修改起、终点位置。

```latex
\draw[->] (-0.2,0) --(6,0) node[right] {$x$};
\draw[->] (0,-0.2) --(0,6) node[above] {$f(x)$};
```

### 函数图像

- `[option]` 指定函数横坐标范围：`[domain=0:4]`
- 用 `\x` 指定自变量：`plot (\x, {0.1 * exp(\x)})`

```latex
\draw[->] (-0.2,0) --(6,0) node[right] {$x$};
\draw[->] (0,-0.2) --(0,6) node[above] {$f(x)$};
\draw[domain =0:4] plot (\x ,{0.1* exp(\x)}) node[right] {$f(x)=\frac{1}{10}e^x$};
```

## 图论应用

### 边

- 无向边：`\draw (0,0) --(5,0) -- (2.5,2.5) -- (0,0);`
- 有向边：`\draw [<-] (5,1) -- (2.5,2.5);`

### 图

- 线性有向图：

    ```latex
    \node [fill,label=below:$c_2$] (1) {};
    \node [label=below:$c_1$] (2) [right of=1] {};
    \node [fill,label=below:$c_2$] (3) [right of=2] {};
    \node [label=below:$c_1$] (4) [right of=3] {};
    \node [fill,label=below:$c_2$] (5) [right of=4] {};
    \node [label=below:$c_1$] (6) [right of=5] {};
    \node [fill,label=below:$c_2$] (7) [right of=6] {};
    \draw 
    	(1) -- (2)
    	(2) -- (3)
    	(3) -- (4)
    	(4) -- (5)
    	(5) -- (6)
    	(6) -- (7);
    ```

- 空心节点无向图：

    ```latex
    %\node (v0) at (0:0) {$v_0$};
    \tikzstyle{every node}=[draw,shape=circle];
    \node (v1) at (0:2) {$v_1$};
    \node (v2) at (72:2) {$v_2$};
    \node (v3) at (2*72:2) {$v_3$};
    \node (v4) at (3*72:2) {$v_4$};
    \node (v5) at (4*72:2) {$v_5$};
    \draw (v1) -- (v2)
    (v2) -- (v3)
    (v3) -- (v4)
    (v4) -- (v5)
    (v1) -- (v5);
    ```

- 实心节点有向图：

    ```latex
    \tikzstyle{every node}=[draw,shape=circle,inner sep=1,minimum size=1.5em];
    \node (v0) at (0:0) [fill,label=below:$v_0$] {};
    \node (v1) at (0:3) [fill,label=below:$v_1$] {};
    \node (v2) at (  72:3) [fill,label=below:$v_2$] {};
    \node (v3) at (2*72:3) [fill,label=below:$v_3$] {$v_3$};
    \node (v4) at (3*72:3) [fill,label=below:$v_4$] {$v_4$};
    \node (v5) at (4*72:3) [fill,label=below:$v_5$] {$v_5$};
    \draw (v0) -- (v1)
    (v0) -- (v2)
    (v0) -- (v3)
    (v0) -- (v4)
    (v0) -- (v5);
    ```

    

## Tikzpicture example

```latex
\begin{center}
    \begin{tikzpicture}
        \draw[red] (0,0) circle [x radius=3.5cm, y radius=2cm] ;
        \draw (3,1.6) node[red]{$V$};
        \draw [blue] (1,0) circle (1.45cm) ;
        \filldraw[blue] (1,0) circle (1pt) node[anchor=north]{$u$};
        \draw (2.9,0.4) node[blue]{$B_r(u)$};
        \draw [green!40!black] (1.7,0) circle (0.5cm) node [yshift=0.7cm]{$B_{\delta}(x)$} ;
        \filldraw[green!40!black] (1.7,0) circle (1pt) node[anchor=west]{$x$};
    \end{tikzpicture}
\end{center}
```

## 参考资料

1. [LaTeX—Tikz 宏包入门使用教程](https://zhuanlan.zhihu.com/p/127155579)
1. [图论Tikz代码 内功心法 上](https://zhuanlan.zhihu.com/p/336249405)

3. [图论Tikz代码-招式篇 下](https://zhuanlan.zhihu.com/p/336668837)