Last update : **8 October, 2023**, *Shanghai*
**Brandon Lin**

------
## 简介

### 什么是NetworkX？

NetworkX是用于研究图论和网络的Python库，内置了常用的图与复杂网络分析算法，可以方便的进行复杂网络数据分析、仿真建模等工作。

### 导入

```python
import network as nx
```

## 基本语法

### 添加和删除

#### 创建和清除图

下列语句用来创建一个没有节点和边的空图

```python
G = nx.Graph()# 无多重边无向图
G = nx.DiGraph()# 无多重边有向图
G = nx.MultiGraph()# 有多重边无向图
G = nx.MultiDiGraph()# 有多重边有向图
```

下列语句用来清除图

```python
G.clear()
```

#### 添加和删除节点

下列语句均可以添加节点

```python
# 添加一个节点a
G.add_node('a')
# 添加节点列表
G.add_nodes_from([2, 3])
# 添加node的Iterable对象
N = nx.path_graph(10)
G.add_nodes_from(N)
# 添加其他的图表、图形作为节点
H = nx.path_graph(10)  # 返回由10个节点的无向图
G.add_nodes_from(H)
```

添加节点时分配属性：[节点属性](#节点属性)
※：注意下列两种语句的区别

```python
G.add_node("spam")        # 添加节点"spam"
G.add_nodes_from("spam")  # 添加4个节点: 's', 'p', 'a', 'm'
```

下列语句用来删除节点

```python
G.remove_node(1)    # 删除指定节点
G.remove_nodes_from(['b','c','d','e'])    # 删除集合中的节点
```

#### 添加和删除边

下列语句均可以添加边

```python
# 添加一条从节点11到节点12的边
F.add_edge(11,12) 
# 添加边列表
G.add_edges_from([(1, 2), (1, 3)])
# 利用包裹传参添加边
e=(13,14)        # e是一个元组
F.add_edge(*e) # 这是python中解包裹的过程
# 利用ebunch (container of edges) 添加边
H = nx.path_graph(10)       # 返回由10个节点的无向图
F.add_edges_from(H.edges()) # 不能写作F.add_edges_from(H) ※:注意和节点区分
```

下列语句用来删除边

```python
G.remove_edge() # 删除单个边
G.remove_edges_from(ebunch) # 删除ebunch中指定的所有边
```

#### 添加一个闭环

```python
# 添加一个节点为f,g,h,j的闭环
G.add_cycle(['f', 'g', 'h', 'j']) 
```

### 访问

#### 对节点相关的访问

```python
nodes(G)  # 在图节点上返回一个迭代器
number_of_nodes(G)  # 返回图中节点的数量
all_neighbors(graph, node)  # 返回图中节点的所有邻居
non_neighbors(graph, node)  # 返回图中没有邻居的节点
common_neighbors(G, u, v)  # 返回图中两个节点的公共邻居

```

#### 对边相关的访问

```python
edges(G[, nbunch]) # 返回与nbunch中的节点相关的边的视图
number_of_edges(G) # 返回图中边的数目
non_edges(graph) # 返回图中不存在的边
G[1][2] # 用下标访问边
G.edges[1,2] # 用下标访问边
```

#### 对邻近的访问

※：对于无向图，邻接迭代可以看到每个边两次。

```python
G.adjacency() # 返回所有节点的迭代器
```

eg：

```python
G = nx.path_graph(4)  # or DiGraph, MultiGraph, MultiDiGraph, etc
[(n, nbrdict) for n, nbrdict in G.adjacency()]
# [(0, {1: {}}), (1, {0: {}, 2: {}}), (2, {1: {}, 3: {}}), (3, {2: {}})]
```

### 属性

#### 图的属性

```python
# 图的属性
G = nx.Graph(day='Monday')    #可以在创建图时分配图的属性
print(G.graph)

G.graph['day'] = 'Friday'     #也可以修改已有的属性
print(G.graph)

G.graph['name'] = 'time'      #可以随时添加新的属性到图中
print(G.graph)

#输出：
#{'day': 'Monday'}
#{'day': 'Friday'}
#{'day': 'Friday', 'name': 'time'}
```

#### 节点属性

```python
# 节点的属性
G = nx.Graph(day='Monday')
G._node()

G.add_node(1, index='1th')             #在添加节点时分配节点属性
# print(G.node(data=True))  #TypeError: 'dict' object is not callable
print(G.node) 
#{1: {'index': '1th'}}


G.node[1]['index'] = '0th'             #通过G.node[][]来添加或修改属性
print(G.node)
# {1: {'index': '0th'}}


G.add_nodes_from([2,3], index='2/3th') #从集合中添加节点时分配属性
print(G.node)
# {1: {'index': '0th'}, 2: {'index': '2/3th'}, 3: {'index': '2/3th'}}

```

#### 边的属性

```python
#边的属性
G = nx.Graph(day='manday')
G.add_edge(1,2,weight=10)                    #在添加边时分配属性
print(G.edges(data=True))
#[(1, 2, {'weight': 10})]

G.add_edges_from([(1,3), (4,5)], len=22)     #从集合中添加边时分配属性
print(G.edges(data='len'))
# [(1, 2, None), (1, 3, 22), (4, 5, 22)]

G.add_edges_from([(3,4,{'hight':10}),(1,4,{'high':'unknow'})])
print(G.edges(data=True))
# [(1, 2, {'weight': 10}), (1, 3, {'len': 22}), (1, 4, {'high': 'unknow'}), (3, 4, {'hight': 10}), (4, 5, {'len': 22})]

G[1][2]['weight'] = 100000                   #通过下标来添加或修改属性
print(G.edges(data=True))
# [(1, 2, {'weight': 100000}), (1, 3, {'len': 22}), (1, 4, {'high': 'unknow'}), (3, 4, {'hight': 10}), (4, 5, {'len': 22})]
```

※：特殊属性 `weight` 应该是数字，因为它被需要加权边缘的算法使用

### 有向图

#### 有向图和无向图互转

有些算法只适用于有向图，而另一些算法不适用于有向图。实际上，将有向图和无向图集中在一起的趋势是危险的。所以有必要进行两者的相互转换。

下列语句和两种图的互转有关

```
#有向图转化成无向图

H=DG.to_undirected()
#或者
H=nx.Graph(DG)

#无向图转化成有向图

F = H.to_directed()
#或者
F = nx.DiGraph(H)

PYTHON
```

#### 有向图添加、删除和访问

有向图的添加、删除和访问和无向图基本上是一样的，在这里不做赘述。

### 图形分析

#### 介数中心性

```
betweenness_centrality(G,k=None,normalized=True,weight=None,endpoints=False, seed=None)
#参数说明
#G--网络图。
#k--如果k不是“无”，则使用k节点样本来估计中间值。k的值<=n，其中n是图中的节点数。值越大，近似值越高。
#归一化--如果为真，则中间值通过 2/((n-1)(n-2)) 对于图，以及 1/((n-1)(n-2)) 对于有向图，其中 n 是g中的节点数。
#权重--如果没有，则认为所有边权重相等。否则将保留用作权重的边缘属性的名称。
#端点--如果为真，则在最短路径计数中包括端点。
#seed--随机数生成状态的指示器。见 Randomness . 请注意，这仅在k不是“无”时使用。

PYTHON
```

更多的算法可见下列站点：

- https://www.osgeo.cn/networkx/reference/algorithms/index.html
- https://networkx.github.io/documentation/stable/reference/algorithms/index.html

### 图片绘制

可以利用matplotlib库进行图形可视化，常见的语句如下：

| draw (g) [, pos, ax] )                           | 用matplotlib绘制图g。   |
| ------------------------------------------------ | ----------------------- |
| draw_networkx (g) [, pos, arrows, with_labels] ) | 使用matplotlib绘制图g。 |
| draw_networkx_nodes (G，POS) [, nodelist, ...] ) | 绘制图G的节点。         |
| draw_networkx_edges (G，POS) [, edgelist, ...] ) | 绘制图G的边。           |
| draw_networkx_labels (G，POS) [, labels, ...] )  | 在图G上绘制节点标签。   |
| draw_networkx_edge_labels (G，POS) [, ...] )     | 绘制边缘标签。          |

除此之外，也可以通过下列语句进行指定节点的**布局**

| bipartite_layout (g,node) [, align, scale, ...] ) | 将节点定位在两条直线上。         |
| ------------------------------------------------- | -------------------------------- |
| circular_layout (g) [, scale, center, dim] )      | 节点在一个圆环上均匀分布         |
| planar_layout (g) [, scale, center, dim] )        | 没有边缘交点的节点分布           |
| random_layout (g) [, center, dim, seed] )         | 在单位正方形内均匀随机定位节点。 |
| shell_layout (g) [, nlist, scale, center, dim] )  | 节点在同心圆上分布               |

下列给出了一些图片绘制中可能用到的**参数**

| pos(dictionary, optional) | 图像的布局，可选择参数；如果是字典元素，则节点是关键字，位置是对应的值。如果没有指明，则会是spring的布局； |
| ------------------------- | ------------------------------------------------------------ |
| arrows                    | 布尔值，默认True; 对于有向图，如果是True则会画出箭头         |
| with_labels:              | 节点是否带标签（默认为True）                                 |
| ax：                      | 坐标设置，可选择参数；依照设置好的Matplotlib坐标画图         |
| nodelist                  | 一个列表，默认G.nodes(); 给定节点                            |
| edgelist                  | 一个列表，默认G.edges();给定边                               |
| node_siz                  | 指定节点的尺寸大小(默认是300)                                |
| node_color                | 指定节点的颜色 (默认是红色，可以用字符串简单标识颜色，具体可查看手册) |
| node_shape:               | 节点的形状（默认是圆形，用字符串’o’标识，具体可查看手册）    |
| alpha                     | 透明度 (默认是1.0，不透明，0为完全透明)                      |
| cmap                      | Matplotlib的颜色映射，默认None; 用来表示节点对应的强度       |
| vmin,vmax                 | 浮点数，默认None;节点颜色映射尺度的最大和最小值              |
| linewidths                | [None\|标量\|一列值];图像边界的线宽                          |
| width                     | 边的宽度 (默认为1.0)                                         |
| edge_color                | 边的颜色(默认为黑色)                                         |
| edge_cmap                 | Matplotlib的颜色映射，默认None; 用来表示边对应的强度         |
| edge_vmin,edge_vmax       | 浮点数，默认None;边的颜色映射尺度的最大和最小值              |
| style                     | 边的样式(默认为实现，可选： solid\|dashed\|dotted,dashdot)   |
| labels                    | 字典元素，默认None;文本形式的节点标签                        |
| font_size                 | 节点标签字体大小 (默认为12)                                  |
| font_color                | 节点标签字体颜色（默认为黑色）                               |
| font_weight               | 字符串，默认’normal’                                         |
| font_family               | 字符串，默认’sans-serif’                                     |

### 图表读写

详见下列站点：

- https://www.osgeo.cn/networkx/reference/readwrite/index.html
- https://networkx.github.io/documentation/stable/reference/readwrite/index.html

## 参考资料

- https://www.osgeo.cn/networkx/index.html
- https://networkx.github.io/documentation/stable/
- https://blog.csdn.net/yyl424525/article/details/102539703

 