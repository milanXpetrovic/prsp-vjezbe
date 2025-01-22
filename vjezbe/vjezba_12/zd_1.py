MOD = 10**9 + 7

class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.is_end = True

    def search(self, s, start, dp):
        node = self.root
        total = 0
        for i in range(start, len(s)):
            if s[i] not in node.children:
                break
            node = node.children[s[i]]
            if node.is_end:
                total = (total + dp[i + 1]) % MOD
        return total

def word_combinations(s, k, words):
    trie = Trie()
    for word in words:
        trie.insert(word)
    
    n = len(s)
    dp = [0] * (n + 1)
    dp[n] = 1  

    for i in range(n - 1, -1, -1):
        dp[i] = trie.search(s, i, dp)
    
    return dp[0]

s = input().strip()
k = int(input().strip())
words = [input().strip() for _ in range(k)]

print(word_combinations(s, k, words))
