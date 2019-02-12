import sys
x1,y1=list(map(int,(raw_input().strip().split())))
x2,y2=list(map(int,(raw_input().strip().split())))
s=0
if(x1==x2 or y1==y2):
    s+=2;
print s+4+2*(abs(x1-x2)+abs(y1-y2))