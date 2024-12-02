def schedule_activities(n, activities):
    activities.sort(key=lambda x: x[1])

    selected_activities = []
    
    last_end_time = -1
    
    for start, end in activities:
        if start >= last_end_time:
            selected_activities.append((start, end))
            last_end_time = end 
    
    return selected_activities

t = int(input())  
activities = []
for _ in range(t):
    start, end = map(int, input().split())
    activities.append((start, end))

result = schedule_activities(t, activities)

for start, end in result:
    print(start, end)
