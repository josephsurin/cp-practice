history = input().lower()
N = int(input())
longest_n = 0
longest_words = []
for _ in range(N):
	w = input()
	if len(w) == longest_n and w in history:
		longest_words.append(w)
	elif len(w) > longest_n and w in history:
		longest_n = len(w)
		longest_words = [w]
for w in longest_words:
	print(w)