_I='nce'
_H='[^A-Z]'
_G='\\d'
_F='two val not equal lol'
_E='[^a-z]'
_D=None
_C='.'
_B='-'
_A=' '
import operator,string,functools,re,math,itertools; from collections import Counter
def arithmetic_operation(n):[n,o,p]=n.split();return dict(zip(['+',_B,'*','//'],[operator.add,operator.sub,operator.mul,operator.floordiv]))[o](int(n),int(p))if int(p)else-1
join_number=lambda n:''.join(map(str,list(range(1,n+1))))
to_boolean_list=lambda w:[not string.ascii_lowercase.index(i)%2 for i in w]
char_to_dots={'A':'.-','B':'-...','C':'-.-.','D':'-..','E':_C,'F':'..-.','G':'--.','H':'....','I':'..','J':'.---','K':'-.-','L':'.-..','M':'--','N':'-.','O':'---','P':'.--.','Q':'--.-','R':'.-.','S':'...','T':_B,'U':'..-','V':'...-','W':'.--','X':'-..-','Y':'-.--','Z':'--..',_A:_A,'0':'-----','1':'.----','2':'..---','3':'...--','4':'....-','5':'.....','6':'-....','7':'--...','8':'---..','9':'----.','&':'.-...',"'":'.----.','@':'.--.-.',')':'-.--.-','(':'-.--.',':':'---...',',':'--..--','=':'-...-','!':'-.-.--',_C:'.-.-.-',_B:'-....-','+':'.-.-.','"':'.-..-.','?':'..--..','/':'-..-.'}
encode_morse=lambda m:_A.join([char_to_dots[i]for i in m.upper()])
sock_merchant=lambda l:sum([l.count(i)//2 for i in set(l)])
majority_vote=lambda l:([i for i in set(l)if l.count(i)>len(l)/2]or[_D])[0]
multiplication_table=lambda n:[[i*j for j in range(1,n+1)]for i in range(1,n+1)]
remove_letters=lambda l,w:[l.pop(l.index(i))for i in w if i in l]and l
unique_styles=lambda a:len(set(','.join(a).split(',')))
missing=lambda l1,l2:[i for i in l1 if l2.count(i)!=l1.count(i)][0]
pluralize=lambda l:set((i+'s'if l.count(i)>1 else i for i in l))
overlapping=lambda l:(l:=sorted(functools.reduce(lambda a,b:a.intersection(b),[set(range(i,j+1))for(i,j)in l])))and(l[0],l[-1])or'No overlapping'
show_the_love=lambda lst:[i+sum((i*0.25 for i in lst if i!=min(*lst)))if i==min(*lst)else i*0.75 for i in lst]
secret=lambda t:"<{0} class='{1}'></{0}>".format(t.split(_C)[0],_A.join(t.split(_C)[1:]))
letters=lambda w1,w2:[''.join(sorted(set(w1).intersection(set(w2)))),''.join(sorted(set(w1).difference(set(w2)))),''.join(sorted(set(w2).difference(set(w1))))]
dakiti=lambda s:_A.join((i[1]for i in sorted(([int(re.search(_G,i)[0]),re.sub(_G,'',i)]for i in s.split()))))
num_split=lambda n:[int([_B,''][n>0]+v+'0'*(len(str(n).replace(_B,''))-i-1))for(i,v)in enumerate(str(n).replace(_B,''))]
identify=lambda *r:'Missing '+str(len(r)*len(max(*r,key=lambda l:len(l)))-len(sum(r,[])))if len(set((len(i)for i in r)))!=1 else['Non-',''][len(r[0])==len(r)]+'Full'
def valid_word_nest(w,s):
	while w in s:
		if s.count(w)>1:return False
		s=s.replace(w,'')
	return len(s)==0
security=lambda s:'ALARM!'if any((i in s.replace('x','')for i in['T$','$T']))else'Safe'
widen_streets=lambda s,n:[''.join(i)for i in zip(*[i if'#'in i else(_A*n,)*len(i)for i in zip(*s)])]
find_pattern=lambda d,p:sorted(('{} = {}'.format(k,p if p in v else _D)for(k,v)in d.items()))
discount=lambda l:[round(i-i*sum(sorted(l)[:len(l)//3])/sum(l),2)for i in l]
class Test:
	@classmethod
	def assert_equals(self,v1,v2,message=_D):print(v1,'<>',v2);assert v1==v2,message or _F
def final(r,c,i):
	lst=[[0 for _ in range(c)]for _ in range(r)];c='r'
	for i in i:
		inc,rc=list(i);inc=int(inc)
		if rc!=c:c=rc;lst=list(zip(*lst))
		lst[inc]=[i+1 for i in lst[inc]]
	return[list(i)for i in(lst if c=='r'else list(zip(*lst)))]
def paul_cipher(w):
	l=string.ascii_uppercase;n=[]
	for (i,v) in enumerate(w.upper()):
		if v in l and i:s=re.sub(_H,'',w.upper()[:i]);s=l.index(v)+1+(l.index(s[-1])if s else-1);n.append(l[s-26 if s>=26 else s])
		else:n.append(v)
	return ''.join(n)
def encrypt(key,message):key=dict(map(list,sum(([key[i:i+2],key[i:i+2][::-1]]for i in range(0,len(key),2)),[])[::-1]));return ''.join((key[i]if i in key else i for i in message))
def spartans_cipher(message,n_Slide):
	r=math.ceil(len(message)/n_Slide)
	if not r:return''
	return ''.join((''.join(i).ljust(n_Slide)for i in itertools.zip_longest(*[message[i:i+r]for i in range(0,len(message),r)],fillvalue=_A))).strip()
def secret_password(m):
	l=string.ascii_lowercase
	if not re.match('^[a-z]{9}$',m):return'BANG! BANG! BANG!'
	p1,p2,p3=[m[i:i+3]for i in range(0,9,3)];p1=f"{l.index(p1[0])+1}{p1[1]}{l.index(p1[2])+1}";p2=p2[::-1];p3=''.join((l[l.index(i)+1]if l.index(i)<25 else'a'for i in p3));return p2+p3+p1
decrypt=lambda s:''.join((string.ascii_lowercase[int(i)-1]for i in re.split('(\\d{2})#|(\\d{1})',s)if i))
func=lambda num:sum(map(int,list(str(num))))-len(str(num))**2
def keyword_cipher(key,message):k=[];l=string.ascii_lowercase;[k.append(i)for i in key if i not in k];key=dict(zip(l,''.join(k)+''.join((i for i in l if i not in key))));return ''.join((key[i]if i in key else i for i in message))
def tap_code(text):A='k';l=string.ascii_lowercase.replace(A,'');return ''.join((l[(n-1)*5+o-1]for(n,o)in[map(len,i.split())for i in re.findall('(\\.+\\s\\.+)',text)]))if _C in text else _A.join(('. ...'if i==A else '{} {}'.format(_C*(l.index(i)//5+1),_C*(l.index(i)%5+1))for i in text))
def encryption(txt):t=txt.replace(_A,'');c=math.ceil(math.sqrt(len(t)));return _A.join((''.join(i)for i in itertools.zip_longest(*(t[i:i+c]for i in range(0,len(t),c)),fillvalue='')))
def nico_cipher(message,key):
	key=list(key);k=[[i,*v]for(i,v)in enumerate(sorted(Counter(key).items()),start=1)];nk=[0 for i in range(len(key))]
	for (i,v,c) in k:
		for _ in range(c):nk[key.index(v)]=i;key[key.index(v)]=_B
	key=nk;val=''.join((''.join(i)for i in zip(*[i[1]for i in sorted(zip(key,zip(*[message[i:i+len(key)].ljust(len(key))for i in range(0,len(message),len(key))])),key=lambda x:(x[0],-len([i for i in x[1]if i])))])));return val
def condi_cipher(message,key,shift):
	key=list(dict.fromkeys(key));key=dict(enumerate(key+[i for i in string.ascii_lowercase if i not in key],start=1));rkey={v:k for(k,v)in key.items()};em_first=rkey[message[0]]+shift;em=key[em_first if em_first<26 else em_first-25]
	for (i,v) in enumerate(message[1:],start=1):
		if v in string.ascii_lowercase:s=re.sub(_E,'',message[:i])[-1];n=rkey[v]+rkey[s];em+=key[n if n<=26 else n-26]
		else:em+=v
	return em
def numbers_to_ranges(lst):
	if not lst:return[]
	l=[[lst[0]]]
	for v in lst[1:]:
		if v-l[-1][-1]==1:l[-1].append(v)
		else:l.append([v])
	return[f"{i[0]}-{i[-1]}"if len(i)>1 else str(i[0])for i in l]
palindrome_descendant=lambda n:len(str(n))>1 and(str(n)==str(n)[::-1]or palindrome_descendant(int(''.join((str(sum(map(int,i)))for i in[str(n)[i:i+2]for i in range(0,len(str(n)),2)])))))
def c_cipher(message,key):
	key=list(key);k=[[i,*v]for(i,v)in enumerate(sorted(Counter(key).items()),start=1)];nk=[0 for i in range(len(key))]
	for (i,v,c) in k:
		for _ in range(c):nk[key.index(v)]=i;key[key.index(v)]=_B
	key=nk
	if _A in message:message=re.sub('[^a-z0-9]','',message.lower());val=''.join([''.join(i[1])for i in sorted(zip(key,zip(*[message[i:i+len(key)].ljust(len(key),'x')for i in range(0,len(message),len(key))])),key=lambda x:(x[0],-len([i for i in x[1]if i])))]);return val
	else:c=len(message)//len(key);val=''.join((''.join((i[1]for i in sorted(enumerate(i,start=1),key=lambda x:key.index(x[0]))))for i in zip(*(message[i:i+c]for i in range(0,len(message),c)))));return val
def ragbaby_cipher(message,key):k=[];[k.append(i)for i in key if i not in k];key=k;key=key+[i for i in string.ascii_lowercase if i not in key];return ''.join(([lambda x:x,str.upper][v.isupper()](key[key.index(v.lower())+i if key.index(v.lower())+i<26 else key.index(v.lower())+i-26])if v.lower()in key else v for i in re.split('([^a-zA-Z]+)',message)for(i,v)in enumerate(i,start=1)))
def trifid_cipher(k,p,m):d=lambda x:k.index(x);return ''.join((k[x*9+y*3+z]for(x,y,z)in[i for i in sum([[sum(zip(*[sum([[d(i)//9,(d(i)-d(i)//9*9)//3,(d(i)-d(i)//9*9)%3]for i in m],[])[i:i+3]for i in range(0,len(m)*3,3)][i:i+p]),())[j:j+3]for j in range(0,p*3,3)]for i in range(0,len(m),p)],[])if i]))
def spartans_cipher(message,n_Slide):
	r=math.ceil(len(message)/n_Slide)
	if not r:return''
	return[''.join(i).ljust(n_Slide)for i in itertools.zip_longest(*[message[i:i+r]for i in range(0,len(message),r)],fillvalue=_A)]
spartans_decipher=lambda m,n:''.join((''.join(i)for i in itertools.zip_longest(*[m[i:i+n]for i in range(0,len(m),n)],fillvalue=''))).strip()
def iterative_ciph(n,m):
	s=[i for(i,v)in enumerate(m)if v==_A]
	for _ in range(n):m=list(m.replace(_A,''));m=m[-n:]+m[:-n];[m.insert(i,_A)for i in s];m=''.join(m).split(_A);m=_A.join((i[-n%len(i):]+i[:-n%len(i)]for i in m))
	return f"{str(n)} {m}"
same_vowel_group=lambda w:[w[0]]+[i for i in w[1:]if all((j in w[0]for j in i if j in'aeiou'))]
def is_palindrome(p):p=re.sub(_E,'',p.lower());return p[0]==p[-1]and is_palindrome(p[1:-1])if len(p)>0 else True
reverse_sort=lambda t:_A.join(sorted(t.split(),key=lambda x:(len(x),''.join((''.join(i)for i in zip(string.ascii_lowercase,string.ascii_uppercase))).index(x[0])))[::-1])
incremental_depth=lambda l:[l[0],incremental_depth(l[1:])]if len(l)>=2 else l
can_put=lambda t,d:d[0]*d[1]>=len(t)and all((len(i)<=d[1]for i in t.split()))
diagonalize=lambda n,d:[[c+r for c in range(n)][::-1 if d[1]=='r'else 1]for r in range(n)][::-1 if d[0]=='l'else 1]
is_magic=lambda s:set(sum(s,[]))==set(range(1,len(s)**2+1))and len(set(list(set((sum(i)for i in s)))+list(set((sum(i)for i in zip(*s))))+[sum([s[i][i]for i in range(len(s))]),sum([s[i][-i-1]for i in range(len(s))])]))==1
diamond_sum=lambda n:sum((i*n+j+1 for(i,j)in set(sum([[(i,abs(n//2-i)),(i,n-abs(n//2-i)-1)]for i in range(n)],[]))))
is_happy=lambda n:n==1 or n!=4 and is_happy(sum([int(i)**2 for i in str(n)]))
closing_in_sum=lambda n:int(n)if len(str(n))==1 else 0 if not len(str(n))else int(str(n)[0]+str(n)[-1])+closing_in_sum(str(n)[1:-1])
collect=lambda s,n:[]if len(s)<n else[s]if len(s)==n else sorted([s[:n]]+collect(s[n:],n))
class Employee:
	def __init__(self,name,**kwargs):self.firstname,self.lastname=name.split();self.__dict__.update(kwargs)
fibo=lambda n: fibo(n-1) + fibo(n-2) if n>0 else 1
x=lambda n:int(n)if len(n)==1 else x(str(sum(map(int,n))))
super_digit=lambda n,k:x(n*k)
def space_message(txt):t=re.sub('\\[(\\d)(\\w+)\\]',lambda x:int(x[1])*x[2],txt);return t if'['not in t else space_message(t)
can_complete=lambda i,w:bool(re.match('^'+'.*?'.join(list(i))+'$',w))
switcheroo=lambda t:re.sub('(nce|nts)(?!\\w)',lambda x:['nts',_I][x.group()!=_I],t)
def p(c,g):return c if len(c)<=g else p(c[:-g],g)+_B+c[-g:]
def license_plate(c,g):return p(c.replace(_B,'').upper(),g)
f=lambda n,c=['b','a']:f(n-1,c+[c[-1]+c[-2]])if n!=0 else c
fibo_word=lambda n:', '.join(f(n-2))if n>1 else'invalid'
def snakefill(n):
	n=n**2;m=0
	while n>=1:n=n//2;m+=1
	return m-1
fact_of_fact=lambda n:eval('*'.join((str(eval('*'.join([str(i)for i in range(1,i+1)])))for i in range(1,n+1))))
is_disarium=lambda n:sum((int(v)**(i+1)for(i,v)in enumerate(str(n))))==n
check_score=lambda s:max(sum(({'#':5,'O':3,'X':1,'!':-1,'!!':-3,'!!!':-5}[i]for i in sum(s,[]))),0)
same_letter_pattern=lambda i,j:len(set((str([{v:i for(i,v)in enumerate(j)}[i]for i in j])for j in[i,j])))==1
is_ascending=lambda s:any((all((j-i==1 for(i,j)in zip(i,i[1:])))for i in[[int(s[j:j+i])for j in range(0,len(s),i)]for i in range(1,len(s)//2+1)if not len(s)%i]))
def hidden_anagram(t,p):t,p=re.sub(_E,'',t.lower()),re.sub(_E,'',p.lower());return([t[i:i+len(p)]for i in range(0,len(t)-len(p)+1)if sorted(t[i:i+len(p)])==sorted(p)]or['noutfond'])[0]
switch_gravity_on=lambda lst:[list(i)for i in zip(*[sorted(i)[::-1]for i in zip(*lst)])]
def final_countdown(lst):
	if not lst:return[0,[]]
	l=[[lst[0]]]
	for (i,v) in enumerate(lst[1:],start=1):
		if l[-1][-1]-v==1:l[-1].append(v)
		else:l.append([v])
	l=[i for i in l if i[-1]==1];return[len(l),l]
def vigenere(t,k):s=string.ascii_uppercase;l=[s[i:]+s[:i]for i in range(26)];u=re.sub(_H,'',t.upper());c=(k*(len(u)//len(k)+1))[:len(u)].upper();return ''.join((l[s.index(c[i])][s.index(v)]if _A in t else l[0][l[s.index(c[i])].index(v)]for(i,v)in enumerate(u)))
def freq_count(l,e,v=0,c={}):
	if not l:return c
	c[v]=l.count(e);c=freq_count(sum([i for i in l if isinstance(i,list)],[]),e,v+1,c);return[list(i)for i in c.items()]if isinstance(c,dict)else c
climbing_leaderboard=lambda r,p:[sorted(sorted(dict.fromkeys(r),key=lambda x:r.index(x))+[i])[::-1].index(i)+1 for i in p]
def is_early_bird(r,n):l=[list(range(i.start(1),i.end(1)))for i in re.finditer('(?=({}))'.format(n),''.join(map(str,range(r+1))))];return l+(['Early Bird!']if len(l)>1 else[])
class Testpaper:
	def __init__(self,subject,markscheme,mark_to_pass):self.subject=subject;self.markscheme=markscheme;self.mark_to_pass=int(mark_to_pass[:-1]);self.pass_mark=mark_to_pass
class Student:
	def __init__(self):self.tests_taken='No tests taken'
	def take_test(self,test,answer):
		correct=[v==test.markscheme[i]for(i,v)in enumerate(answer)].count(1);mark=round(correct/len(test.markscheme)*100)
		if not isinstance(self.tests_taken,dict):self.tests_taken={}
		self.tests_taken[test.subject]='%s! (%d%%)'%(['Failed','Passed'][mark>=test.mark_to_pass],mark)
class player:
	def __init__(self,name,age,height,weight):self.name=name;self.age=age;self.height=height;self.weight=weight;self.get_age=lambda:'{} is age {}'.format(self.name,self.age);self.get_height=lambda:'{} is {}cm'.format(self.name,self.height);self.get_weight=lambda:'{} weighs {}kg'.format(self.name,self.weight)
class Test:
	@classmethod
	def assert_equals(self,v1,v2,message=_D):print(v1,'<>',v2);assert v1==v2,message or _F
	@classmethod
	def assert_not_equals(self,v1,v2,message=_D):print(v1,'<!>',v2);assert v1!=v2,message or _F
def make_dartboard(n):
	if n==1:return[1]
	l=['1'*n];[l.append(l[-1][:i]+str(i+1)*(n-i*2)+l[-1][-i:])for i in range(1,n//2+n%2)];return[int(i)for i in l+l[::-1][n%2:]]
title_to_number=lambda s:sum(((string.ascii_uppercase.index(v)+1)*26**(len(s)-i-1)for(i,v)in enumerate(s)))
class Pizza:
	order_number=0
	def __init__(self,ingredients=_D):self.ingredients=ingredients;Pizza.order_number+=1;self.order_number=Pizza.order_number
	@staticmethod
	def garden_feast():return Pizza(['spinach','olives','mushroom'])
	@staticmethod
	def hawaiian():return Pizza(['ham','pineapple'])
	@staticmethod
	def meat_festival():return Pizza(['beef','meatball','bacon'])
f=lambda n:1 if n==1 or n==0 else n*f(n-1)
def nespers(lst,n=1):
	n*=f(len(lst))
	for i in lst:
		if isinstance(i,list):n=nespers(i,n)
	return n
nespers=lambda lst:f(len(lst))*functools.reduce(lambda a,b:a*b,[nespers(i)for i in lst if type(i)==list],1)
def minesweeper(g):
	m,c=[[i,j]for(i,v)in enumerate(g)for(j,v)in enumerate(v)if v=='?'],[(1,0),(0,1),(-1,0),(0,-1),(1,1),(-1,-1),(-1,1),(1,-1)]
	for m in m:g[m[0]][m[1]]=str([g[m[0]-i][m[1]-j]for(i,j)in c if 0<=m[0]-i<len(g)and 0<=m[1]-j<len(g[0])].count('#'))
	return g
harry=lambda p:max(sum(p[0])+sum(list(zip(*p[1:]))[-1]),sum(list(zip(*p))[0])+sum(p[-1][1:]))if len(p[0])>1 else p[0][0]if p[0]else-1

