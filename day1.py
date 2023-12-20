with open("input.txt", "r") as f:
    content = f.readlines()
    total = 0
    for line in content:
        num = 0
        for _, word in enumerate(line):
            if word.isdigit():
                num = num + (10 * int(word))
                break
        
        for _, word in enumerate(reversed(line)):
            if word.isdigit():
                num = num + int(word)
                break
        total += num 
    print(total)

