dic = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

n = int(n)
m = int(m)
t = int(t)

for i in range(n):
	inp = input();
	for j in range(m):
		if inp[j] == 'Y':
			dic[j] += 1

result = 0
for i in range(m):
	if dic[i] >= t:
		result += 1

print (result)
# :3
# kitten