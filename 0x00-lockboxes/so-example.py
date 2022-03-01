""" Module for 0-lockboxes """

def join(T,R):
  res =[]
  for e in R:
    res += T[e]
  return res

def canUnlockAll(boxes) -> bool:
    """ canUnlockAll - checks if all boxes are unlocked """
    index = 0
    total = list(set(boxes[0]) | {0})
    added = True
    while added:
        added = False
        for j in join(boxes, total[index:]):
            if j not in total:
                total.append(j)
                index += 1
                added = True
    print(total)
    return len(total)==len(boxes)

boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
print(canUnlockAll(boxes))