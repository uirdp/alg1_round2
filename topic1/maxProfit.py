
minv = 20000000000
maxv = -20000000000
val = 0

n  = int(input())
for i in range(n):
  
  val = int(input())
  maxv = max(maxv, (val - minv))
  minv = min(minv, val)

print(maxv)