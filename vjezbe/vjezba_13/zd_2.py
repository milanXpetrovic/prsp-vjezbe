import sys

def point_location_test():
    t = int(sys.stdin.readline().strip())
    results = []
    
    for _ in range(t):
        x1, y1, x2, y2, x3, y3 = map(int, sys.stdin.readline().split())
        cross = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)
        
        if cross > 0:
            results.append("LEFT")
        elif cross < 0:
            results.append("RIGHT")
        else:
            results.append("TOUCH")
    
    sys.stdout.write("\n".join(results) + "\n")

point_location_test()
