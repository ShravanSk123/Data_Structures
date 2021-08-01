class Node:
	def __init__(self, data):
		self.data = data
		self.left = self.right = None

    
def leveltraversal(root):
    if root is None:
        return
    queue = []
    
    queue.append(root)
    while len(queue)>0:
        temp = queue.pop(0) # pop first element
        print(temp.data, " ", end="")
        if temp.left:
            queue.append(temp.left)
        if temp.right:
            queue.append(temp.right)
        
	
# main
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.left = Node(6)
root.right.right = Node(7)
leveltraversal(root)

