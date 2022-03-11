from functools import reduce
import math
from itertools import zip_longest,combinations
import string
from collections import Counter
a=string.ascii_lowercase
alphabet=string.ascii_lowercase

def mirror_cipher(message,key=string.ascii_lowercase):return ''.join((key[::-1][key.index(i)]if i in key else i for i in message.lower()))
def staircase(n,o=0):return((o-1)*'_'+'#'if n==1 else '\n'.join([staircase(n-1,o if o else n),(o-n)*'_'+n*'#']))if n>0 else o*'#'if n==-1 else '\n'.join([staircase(n+1,o if o else abs(n)),(abs(n)-1)*'_'+((o if o else abs(n))-abs(n)+1)*'#'])
def longest_abecedarian(lst):return max([i for i in lst if all((i[j]<=i[j+1]for j in range(len(i)-1)))]or[''],key=lambda x:len(x))
def palindrome_sieve(lst):return[i for i in lst if str(i)[::-1]==str(i)or not Counter([i%2==0 for i in Counter(str(i)).values()]).get(False,0)-len(str(i))%2]
def true_equations(lst):return[i for i in lst if eval(i.replace('=','=='))]
def loves_me(n):return ', '.join(([lambda i:i,str.upper][i+1==n]('Loves me'+(' not'if i%2 else''))for i in range(n)))
def invert(s):return s.swapcase()if len(s)==1 else s[-1].swapcase()+invert(s[:-1])
def alphabet_index(alphabet,string):
	highest=0
	for i in string.lower():
		if alphabet.index(i)>highest:highest=alphabet.index(i)
	return f"{highest+1}{alphabet[highest]}"
def num_type(n):
	x=sum((i for i in range(1,n)if not n%i))
	if x==n:return'Perfect'
	if sum((i for i in range(1,x)if not x%i))==n:return'Amicable'
	return'Neither'
def is_icecream_sandwich(txt):
	if len(txt)<3:return False
	sw=[txt[0]];[sw.append(i)for i in txt[1:]if i!=sw[-1]];return len(sw)==3 and sw[0]==sw[-1]and len(set((i for i in txt.split(sw[1])if i)))==1
def compress(chars):
	cur=[chars[0]];res=[1]
	for i in chars[1:]:
		if cur[-1]==i:res[-1]+=1
		else:cur.append(i);res.append(1)
	return ''.join((''.join(i)for i in zip(cur,map(str,[i if i>1 else''for i in res]))))
def alpha_range(s,t,e=1):
	l=string.ascii_lowercase
	if not e or not-26<e<26:return'step must be a non-zero value between -26 and 26, exclusive'
	if not any((s in i and t in i for i in[l.upper(),l])):return'both start and stop must share the same case'
	f=sorted((l.index(i.lower())for i in[s,t]))[::-1 if e<0 else 1];f[1]=None if f[1]==0 else f[1]-1 if e<0 else f[1]+1;r=l[slice(*f,e)];return list(r if s in l else r.upper())
def mangle(txt):s=string.ascii_lowercase+'a'+string.ascii_uppercase+'A';return ''.join(([lambda i:i,str.upper][s[s.index(i)+1].lower()in'aeiou'](s[s.index(i)+1])if i in s else i for i in txt))
def shadow_sentence(a,b):a,b=a.split(),b.split();return len(a)==len(b)and all((len(a[i])==len(b[i])and not len(set(a[i]).intersection(set(b[i])))for i in range(len(a))))
def fiscal_code(person):
	months={'1':'A','2':'B','3':'C','4':'D','5':'E','6':'H','7':'L','8':'M','9':'P','10':'R','11':'S','12':'T'}
	def getSurnameCode(w):c=''.join(filter(lambda x:x not in'AEIOU',w.upper()))[:3];v=''.join(filter(lambda x:x in'AEIOU',w.upper()))[0:3-len(c)];x='X'*(3-len(c+v));return c+v+x
	def getNameCode(w):
		c=''.join(filter(lambda x:x not in'AEIOU',w.upper()))
		if len(c)>3:c=c[0]+c[2]+c[3]
		v=''.join(filter(lambda x:x in'AEIOU',w.upper()))[0:3-len(c)];x='X'*(3-len(c+v));return c+v+x
	return getSurnameCode(person['surname'])+getNameCode(person['name'])+person['dob'][-2:]+months[person['dob'].split('/')[1]]+[lambda i:i.zfill(2),lambda i:str(int(i)+40)][person['gender']=='F'](person['dob'].split('/')[0])
def almost_sorted(lst):return 1 in Counter((lst[i]<lst[i+1]for i in range(len(lst)-1))).values()
def kaprekar(num):n=''.join(sorted(str(num).zfill(4)));n=abs(int(n)-int(n[::-1]));return 0 if num==6174 else 1+kaprekar(n)
def single_number(nums):return{v:k for(k,v)in Counter(nums).items()}[1]
def odd_sort(lst):even=iter(sorted((i for i in lst if i%2 and i)));res=[i if not i%2 or i==0 else next(even)for i in lst];return res
def product_equal_target(lst,target):
	lst=sorted(lst)[::-1];res=[0 for i in range(len(lst))]
	for (i,v) in enumerate(lst):
		while target//v==target/v:target//=v;res[i]+=1
	return res[::-1]
def combo(l,n):list(map(list,combinations(l,n)))
def combo(lst,n):
	if not n:return[[]]
	target=[]
	for i in range(len(lst)):
		for p in combo(lst[i+1:],n-1):target.append([lst[i]]+p)
	return target
def reverse(s):return''if not s else s[-1]+reverse(s[:-1])
def gpa_calculator(s):return '{} GPA for {} is {}'.format(s['name'],s['semester'],'{:.2f}'.format(sum((i['credit_hours']*'FDCBA'.index(i['grade'])for i in s['courses']))/sum((i['credit_hours']for i in s['courses']))))
def maximum_items(prices,budget):
	budget=int(budget[1:]);items=sorted((int(i[1:])for i in prices));can_buy=0
	for i in items:
		if budget-i<0:break
		can_buy+=1;budget-=i
	return can_buy if can_buy else'Not enough funds!'
def mineSweeper():
	input1=input('Please enter the row count, column count and mine count of your board: ');splittedInput1=input1.split();rows,cols,mineCount=[int(i)for i in splittedInput1];mine=[[''for i in range(cols)]for i in range(rows)]
	for i in range(mineCount):mineCoorsInput=input(f"Please enter the x and y coordinate of mine #{i}: ");mineRow,mineCol=[int(i)for i in mineCoorsInput.split()];mine[mineRow][mineCol]='*'
	neighbour=[[-1,-1],[-1,0],[-1,1],[0,-1],[0,1],[1,-1],[1,0],[1,1]]
	for i in range(rows):
		for j in range(cols):
			if mine[i][j]!='*':
				neighbourSUSCount=0
				for n in range(len(neighbour)):
					if i+neighbour[n][0]>=0 and i+neighbour[n][0]<rows:
						if j+neighbour[n][1]>=0 and j+neighbour[n][1]<cols:
							if mine[i+neighbour[n][0]][j+neighbour[n][1]]=='*':neighbourSUSCount+=1
				mine[i][j]=str(neighbourSUSCount)
	print('\n'.join((''.join(i)for i in mine)));return
def perrin(n):
	if n==2:return 2
	if n==1:return 0
	if n==0:return 3
	return perrin(n-2)+perrin(n-3)
def post_fix(s):return eval(''.join((''.join(i)for i in zip_longest([i for i in s.split()if i.isdigit()],[i for i in s.split()if not i.isdigit()],fillvalue=''))))
def happiness_number(s):return sum([[-1,1][s[i]+s[i+1]in':)(:']for i in range(len(s)-1)if s[i]+s[i+1]in':),(:):,:('])
def max_possible(n1,n2):
	n1=list(str(n1));n2=sorted(str(n2))
	for (j,v) in enumerate(n1):
		if n2 and v<n2[-1]:n1[j]=n2.pop()
	return int(''.join(n1))
def cars(w,b,f):return min(w//4,b,f//2)
def sums_of_powers_of_two(n):return[int(v)*2**i for(i,v)in enumerate(str(bin(n)[2:][::-1]))if int(v)]
def sum_missing_numbers(lst):return sum(set(range(min(lst),max(lst)+1))-set(lst))
def pascal_triangle(layer):
	res=[[1]]
	for i in range(1,layer):
		res.append([])
		for j in range(i+1):res[-1].append((res[-2][j-1]if j-1>=0 else 0)+(res[-2][j]if j<len(res[-2])else 0))
	return res
def can_give_blood(d,r):return not(d[-1]=='+'and r[-1]!='+')and(d[:-1]in r[:-1]or d[:-1]=='O')
def mubashir_cipher(message):key=[['m','c'],['u','e'],['b','g'],['a','k'],['s','v'],['h','x'],['i','z'],['r','y'],['p','w'],['l','n'],['o','j'],['t','f'],['q','d']];return ''.join((dict(key+[i[::-1]for i in key])[i]if i.isalpha()else i for i in message))
def binary_to_text(str):return ''.join((chr(int(str[i:i+8],2))for i in range(0,len(str),8)))
def odd_one_out(lst):lst=Counter([len(i)for i in lst]);return bool(len(lst)==2 and {v:i for(i,v)in lst.items()}.get(1))
def hex_color_mixer(lst):return'#'+''.join((hex(sum(i)//len(lst)+(sum(i)/len(lst)-sum(i)//len(lst)>=0.5))[2:].zfill(2)for i in zip(*[[int(i[1:][j:j+2],16)for j in range(0,6,2)]for i in lst]))).upper()
def missing_alphabets(txt):max_=max((txt.count(i)for i in txt));return ''.join([i*(max_-txt.count(i))for i in string.ascii_lowercase])
def eval_algebra(eq):
	num1,operator,num2,_,num3=eq.split()
	if num1=='x':return eval(num3+{'+':'-','-':'+'}[operator]+num2)
	if num2=='x':return eval('{}({})'.format(operator,num3+'-'+num1))
	else:return eval(num1+operator+num2)
def is_isomorphic(s,t):
	hash_map={}
	for (i,v) in enumerate(t):
		if v in hash_map:
			if hash_map[v]!=s[i]:return False
		else:hash_map[v]=s[i]
	return True
def floyd(up_to=None,n_row=None):
	def n(i):return int(1/2*i*(i+1)+1)
	if n_row:return[list(range(n(i),n(i)+i+1))for i in range(0,n_row)]
	if up_to:
		res=[];i=0
		while up_to>=n(i)+i+1 or up_to in range(n(i),n(i)+i+1):res.append(list(range(n(i),n(i)+i+1)));i+=1
		return res
def shift_sentence(txt):txt=[txt.split()[-1]]+txt.split();return ' '.join((txt[i-1][0]+txt[i][1:]for i in range(1,len(txt))))
def pyramidal_string(string,_type):
	res=[]
	if _type=='REV':string=list(reversed(string))
	cur=1
	while len(string)>=cur:res.append(' '.join(list(string[:cur])));string=string[cur:];cur+=1
	if len(string):return'Error!'
	if _type=='REV':res=list(reversed([i[::-1]for i in res]))
	return res
def sun_loungers(str):
	if str=='0':return 1
	if str=='000':return 2
	count=0;str=[i for i in ('1'+str+'1').split('1')]
	for (i,v) in enumerate(str):
		if v:count+=v=='00'or math.floor(len(v)/2)if i==len(str)-2 or i==1 else math.ceil((len(v)-2)/2)if v not in['0','00']else 0
	return count
def fib_str(n, f):
    return f[0]if n==1 else ', '.join([f[0],fib_str(n-1,[f[1],f[1]+f[0]])])

def crop_hydrated(lst):
	neighbour=[[-1,-1],[-1,0],[-1,1],[0,-1],[0,1],[1,-1],[1,0],[1,1]]
	for i, v in enumerate(lst):
		for j, w in enumerate(v):
			if w=='c':
				can_pass = False
				for n in neighbour:
					if i+n[0]>=0 and i+n[0] < len(lst):
						if j+n[1]>=0 and j+n[1] < len(lst[0]):
							if lst[i+n[0]][j+n[1]] == 'w':
								can_pass = True
				if not can_pass: return False
	return True

def who_passed(marks):
	return sorted(k for k, v in marks.items() if all(eval(w) == 1 for w in v))

def constraint(s):
	s = [i.lower() for i in s if i.isalpha() or i == " "]
	if len(set(string.ascii_lowercase+(" " if " " in s else "")) - set(s)) == 0: return "Pangram"
	if len(set(i for i in s if i != " ")) == len([i for i in s if i != " "]): return "Heterogram"
	if len(set(i[0] for i in "".join(s).split())) == 1: return "Tautogram"
	if bool(reduce(lambda x, y: x.intersection(y), [set(i) for i in "".join(s).split()])): return "Transgram"
	return "Sentence"

from itertools import permutations
def jumble(txt, index):
	return "".join(list(permutations(txt, len(txt)))[index])

class Test:
	@classmethod
	def assert_equals(self,v1,v2,message=''):
		print(v1,'<>',v2);
		assert v1==v2,message or'two val not equal lol'
	@classmethod
	def assert_not_equals(self,v1,v2,message=''):print(v1,'<!>',v2);assert v1!=v2,message or'two val not equal lol'

def cup_swapping(swaps):
	cups = {"A": 0, "B": 1, "C": 0}
	for i in swaps:
		if cups[i[0]] or cups[i[1]]:
			cups[i[0]], cups[i[1]] = cups[i[1]], cups[i[0]]
	return [i for i in cups if cups[i]][0]

t = 10

while (t:=t-1):
	print(t)