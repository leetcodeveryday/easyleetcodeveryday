from math import *
def if_reverso(line):#输入字符串判断是否是回文串
    if line==line[::-1]:
        return [1,line]
    else:
        return [0,line]

def extrator(Line):#读取字符串并且返回所有字串
    num=len(Line)
    strlist=[]
    for i in range(num-1):
        for j in range(i+2,num+1):
            strlist.append(Line[i:j])
    return strlist

if __name__=="__main__":

    Line = input('请输入字符串：')

    max_line=[0,""]
    strlist=extrator(Line)
    for i in strlist:
        if if_reverso(i)[0]:
            if len(i)>max_line[0]:
                max_line[0]=len(i)
                max_line[1]=i
            else:
                continue
        else:
            continue
    print(max_line[1])