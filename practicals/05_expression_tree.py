class Node:
    def __init__(self, value):
        self.value = value
        self.left = self.right = None

def build(postfix):
    stack = []
    for x in postfix:
        if x.isdigit():
            stack.append(Node(x))
        else:
            n = Node(x)
            n.right = stack.pop()
            n.left = stack.pop()
            stack.append(n)
    return stack[-1]

def inorder(n):
    if n.left is None:
        return n.value
    return "(" + inorder(n.left) + n.value + inorder(n.right) + ")"

def preorder(n):
    if n is None: return []
    return [n.value] + preorder(n.left) + preorder(n.right)

def postorder(n):
    if n is None: return []
    return postorder(n.left) + postorder(n.right) + [n.value]

def evaluate(n):
    if n.left is None: return int(n.value)
    a, b = evaluate(n.left), evaluate(n.right)
    if n.value == '+': return a+b
    if n.value == '-': return a-b
    if n.value == '*': return a*b
    return a//b

root = build("35+2*")
print("Inorder:", inorder(root))
print("Preorder:", *preorder(root))
print("Postorder:", *postorder(root))
print("Result:", evaluate(root))