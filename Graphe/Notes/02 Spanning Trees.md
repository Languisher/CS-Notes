Last update : **September, 2023**, *Shanghai*
**Brandon Lin**

Un parcours de graphe est un algorithme consistant à explorer les sommets d’un graphe de proche en proche à partir d’un sommet initial.

Les deux algorithmes de parcours les plus connus sont :
1. l’algorithme de parcours en largeur
2. l’algorithme de parcours en profondeur

## Breadth-First Search (BFS)

### Presentation
L’**algorithme de parcours en largeur** (ou BFS pour Breadth-First Search en anglais) consiste à :
- partir d’un sommet,  
- explorer tous ses *voisins*  
- explorer tous les *voisins de ces voisins* (sauf le sommet de départ)
- explorer tous les *voisins non-explorés* des sommets déjà explorés, puis etc.
jusqu’à ce qu’il n’existe plus de voisins non-explorés.

#### Example

![|200](assets/截屏2023-10-08%2010.41.34.png)
![](assets/截屏2023-10-08%2010.41.45.png)
The steps of the breadth-first search procedure are shown in Figure 10. 
- We choose the vertex e to be the root. 
- Then we add edges incident with all vertices adjacent to e, so edges from e to b, d, f , and i are added. These four vertices are at level 1 in the tree. 
- Next, add the edges from these vertices at level 1 to adjacent vertices not already in the tree. Hence, the edges from b to a and c are added, as are edges from d to h, from f to j and g, and from i to k. The new vertices a, c, h, j , g, and k are at level 2. 
- Next, add edges from these vertices to adjacent vertices not already in the graph. This adds edges from g to l and from k to m.
### Algorithm
Procedure : **BFS** 
Given :
- G
- s sommet





## 深度优先搜索（DFS）
深度优先搜索是搜索算法的一种，它从某一个状态开始，不断地转移状态直到无法转移，然后回退到前一步的状态，继续转移到其他状态，如此不断重复，直到找到最终的解。

深度优先搜索在搜索到一个新的节点时，立即对该新节点进行遍历。因此遍历需要用先入后出的栈来实现，也可以通过与栈等价的递归来实现。对于树结构而言，由于总是对新节点调用遍历，因此看起来是向着“深”的方向前进。

下面举例了一个用栈实现的二叉树的深度优先搜索过程。

用深度优先搜索方式遍历二叉树的所有节点，假设左枝优先于右枝，则从根节点1开始，节点的遍历顺序为1,2,4,8,5,3,6,7,9
1. 从根节点1开始搜索，用一个先进后出的栈实现其过程
2. 根节点1入栈
3. 找出一个与该节点邻接且尚未遍历的节点，然后入栈，依次进行



    （4）如果当前节点没有尚未遍历的邻接节点，则将此节点出栈，再执行（3）步骤



    （5）直到遍历完所有节点，将栈中的元素清空，深度优先搜索完成


    深度优先搜索可以用来帮助检测环路：记录每个遍历过的节点的父节点，若一个节点被再次遍历且父节点不同，则说明有环。也可以用拓扑排序判断是否有环路，若最后存在入度不为零的点，则说明有环。 在用深度优先搜索时，有时需要对已经搜索过的节点进行标记，以防止在遍历过程中重复搜索某个节点，这种方法叫状态记录或记忆化（memoization）。

2 广度优先搜索（BFS）
    广度优先搜索又称宽度优先搜索，也是搜索算法的一种，它与深度优先搜索类似，从某个状态出发，搜索所有可以到达的状态。不同于深度优先搜索的是，广度优先搜索是一层层进行遍历的，因此需要用先入先出的队列而非先入后出的栈进行遍历。由于是按层次进行遍历，广度优先搜索时按照“广”的方向进行遍历的，也常常用来处理最短路径等问题。
    下面举例了一个用队列实现的二叉树的广度优先搜索过程。

用广度优先搜索方式遍历二叉树的所有节点，假设左枝优先于右枝，则从根节点1开始，节点的遍历顺序为1,2,3,4,5,6,7,8,9
    （1）从根节点1开始搜索，用一个先进先出的队列实现其过程

    （2）根节点1存入队列

    （3）找出所有与该节点邻接且尚未遍历的节点，然后存入队列


    （4）节点1的所有邻居都已被遍历，将其出队列，然后继续（3）步骤





    （4）直到遍历完所有节点，将队列中的元素清空，广度优先搜索完成



3 总结
    深度优先搜索和广度优先搜索都是常用的图搜索算法，深度优先搜索和广度优先搜索都可以处理可达性问题，即从一个节点开始是否能达到另一个节点，以上两个例子都是在无向图的二叉树中进行的DFS和BFS过程，有向图的深度优先搜索和广度优先搜索还需要考虑边的方向。深度优先搜索常用栈或递归的方式实现，广度优先搜索常用队列的方式实现。
### Code Implementation
```python
def bfs(M, s):
	n = len(M)
	Marquage = [False] * n
	File = [s]
	Marquage[s] = True
	while File != []:
		s = File.pop(0)
		for t in range(n):
			if M[s][t] == 1 and not Maarquage[t] :
				File.append(t)
				Marquage[t] = True
	...
```

#### Test de la connexité
```python
def bfs(M, s):
	...
	for i in range(n):
		if Marquage[i] == False:
			return False
	return True
```

#### Calcul de la composante connexe de $s$
```python
def bfs(M, s):
	...
	Composante = []
	for i in range(n): 
		if Marquage[i] == True :
			Composante.append(i)
	return Composante
```

#### Calcul de la distance
```python
def bfs(L,s):
	n = len(L)
	Marquage = [False] * n
	File = [s]
	Marquage[s] = 0 
	distance = 0 
	while File != []:
		s = File.pop(0)
		distance = Marquage[s] + 1
		for t in L[s]:
			if Marquage[t] == False :
				File.append(t)
				Marquage[t] = distance 
	return Marquage
```

```python
def bfs_matrice(M, s):
	n = len(M)
	Marques = [False]*n
	File_explores = [s]
	Marques[s] = True 
	while ...
```
#### Calcul des distances
```python
def distances(L, s):
	n = len(L)
	Marques = [False]*n
	File_explores = [s]
	Marques[s] = True 
	Dist = [None] *n # list des distances
	Dist[s] = 0 # distance de s à s
	while File_explores != []:
		t= File_explores.pop(0)
		...
```
### DFS
```python
def dfs_liste(L, s):
	n = len(L) # ordre du graphe
	Marques=[False]*n # initialisation du marquage
	Pile_explores=[s] # 'etapes 1 et 2'
	Marques[s]=True # étape 2
	while Pile_explores=[]: # étape 3 et.8
		t = Pile_explores[-1] # dern. som. de la pile
		(v, i) = (None, 0) # i = indice des voisins de t
		while v==None and i<len(L[t]): # chercher v 
			if not (Marques[L[t][i]]): # étape 4 
				v = L[t][i] # trouver v 
				Pile_explores.append(v) # étape 5 
				Marques[v] = True # étape 5 
			i = i + 1 # indice suivant 
		if v == None : # étape 6 
			Pile_explores.remove(t) # étape 7 
	# à compléter
```

```python
(v, i) = (None, 0)
while v == None and i<n:
	if M[t][i] != 0 and not (Marques[i]) :
		v = i 
		Pile_explores.append(v)
		Marques[v] = True
	i = i + 1
if v == None :
	Pile_explores.remove(t)
# à compléter4e
```
## Reference
1. [Breadth First Search](https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/tutorial/)