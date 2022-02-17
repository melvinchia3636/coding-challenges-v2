from random import randint, shuffle
from time import perf_counter
import string
from itertools import accumulate
from collections import Counter

a = string.ascii_lowercase
alphabet = string.ascii_lowercase


def mirror_cipher(message, key=string.ascii_lowercase): return "".join(
    key[::-1][key.index(i)] if i in key else i for i in message.lower())


def staircase(n, o=0): return ((o-1)*"_"+"#" if n == 1 else "\n".join([staircase(n-1, o if o else n), (o-n)*"_"+n*"#"])) if n > 0 else (
    o)*"#" if n == -1 else"\n".join([staircase(n+1, o if o else abs(n)), (abs(n)-1)*"_"+((o if o else abs(n))-abs(n)+1)*"#"])


def longest_abecedarian(lst): return max([i for i in lst if all(
    i[j] <= i[j+1] for j in range(len(i)-1))] or [""], key=lambda x: len(x))
def palindrome_sieve(lst): return [i for i in lst if str(i)[::-1] == str(i) or not Counter(
    [i % 2 == 0 for i in Counter(str(i)).values()]).get(False, 0) - (len(str(i)) % 2)]


def true_equations(lst): return [i for i in lst if eval(i.replace("=", "=="))]


def loves_me(n): return ", ".join(
    [lambda i: i, str.upper][i+1 == n]("Loves me"+(" not" if i % 2 else "")) for i in range(n))


def invert(s): return s.swapcase() if len(
    s) == 1 else s[-1].swapcase() + invert(s[:-1])


def alphabet_index(alphabet, string):
    highest = 0
    for i in string.lower():
        if alphabet.index(i) > highest:
            highest = alphabet.index(i)
    return f"{highest+1}{alphabet[highest]}"


def num_type(n):
    x = sum(i for i in range(1, n) if not n % i)
    if x == n:
        return "Perfect"
    if sum(i for i in range(1, x) if not x % i) == n:
        return "Amicable"
    return "Neither"


def is_icecream_sandwich(txt):
    if len(txt) < 3:
        return False
    sw = [txt[0]]
    [sw.append(i) for i in txt[1:] if i != sw[-1]]
    return len(sw) == 3 and sw[0] == sw[-1] and len(set(i for i in txt.split(sw[1]) if i)) == 1


def compress(chars):
    cur = [chars[0]]
    res = [1]
    for i in chars[1:]:
        if cur[-1] == i:
            res[-1] += 1
        else:
            cur.append(i)
            res.append(1)
    return "".join("".join(i) for i in zip(cur, map(str, [i if i > 1 else "" for i in res])))


def alpha_range(s, t, e=1):
    l = string.ascii_lowercase
    if not e or not -26 < e < 26:
        return "step must be a non-zero value between -26 and 26, exclusive"
    if not any(s in i and t in i for i in [l.upper(), l]):
        return "both start and stop must share the same case"
    f = sorted(l.index(i.lower()) for i in [s, t])[::-1 if e < 0 else 1]
    f[1] = None if f[1] == 0 else f[1]-1 if e < 0 else f[1] + 1
    r = l[slice(*f, e)]
    return list(r if s in l else r.upper())


def mangle(txt):
    s = string.ascii_lowercase+"a"+string.ascii_uppercase+"A"
    return "".join([lambda i: i, str.upper][s[s.index(i)+1].lower() in "aeiou"](s[s.index(i)+1]) if i in s else i for i in txt)


class Test:
    @classmethod
    def assert_equals(self, v1, v2, message=""):
        print(v1, '<>', v2)
        assert v1 == v2, message or 'two val not equal lol'

    @classmethod
    def assert_not_equals(self, v1, v2, message=""):
        print(v1, '<!>', v2)
        assert v1 != v2, message or 'two val not equal lol'


def shadow_sentence(a, b):
    a, b = a.split(), b.split()
    return len(a) == len(b) and all(len(a[i]) == len(b[i]) and not len(set(a[i]).intersection(set(b[i]))) for i in range(len(a)))


def fiscal_code(person):
    months = {"1": "A", "2": "B", "3": "C", "4": "D", "5": "E", "6": "H",
              "7": "L", "8": "M", "9": "P", "10": "R", "11": "S", "12": "T"}

    def getSurnameCode(w):
        c = "".join(filter(lambda x: x not in "AEIOU", w.upper()))[:3]
        v = "".join(filter(lambda x: x in "AEIOU", w.upper()))[0:3-len(c)]
        x = "X" * (3-len(c+v))
        return c + v + x

    def getNameCode(w):
        c = "".join(filter(lambda x: x not in "AEIOU", w.upper()))
        if len(c) > 3:
            c = c[0] + c[2] + c[3]
        v = "".join(filter(lambda x: x in "AEIOU", w.upper()))[0:3-len(c)]
        x = "X" * (3-len(c+v))
        return c + v + x

    return getSurnameCode(person['surname']) + getNameCode(person['name']) + person['dob'][-2:] + months[person['dob'].split('/')[1]] + [lambda i: i.zfill(2), lambda i: str(int(i)+40)][person['gender'] == 'F'](person['dob'].split('/')[0])


def almost_sorted(lst): return 1 in Counter(
    lst[i] < lst[i+1] for i in range(len(lst)-1)).values()


def kaprekar(num):
    n = "".join(sorted(str(num).zfill(4)))
    n = abs(int(n) - int(n[::-1]))
    return 0 if num == 6174 else 1 + kaprekar(n)


def single_number(nums): return {v: k for k, v in Counter(nums).items()}[1]

def odd_sort(lst):
    even = iter(sorted(i for i in lst if i%2 and i))
    res = [i if not i%2 or i == 0 else next(even) for i in lst]
    return res

def product_equal_target(lst, target):
    lst = sorted(lst)[::-1]
    res = [0 for i in range(len(lst))]
    for i, v in enumerate(lst):
        while target // v == target / v:
            target //= v
            res[i] += 1
    return res[::-1]

from itertools import combinations

def combo(l, n): list(map(list, combinations(l, n)))
def combo(lst, n):
    if not n: return [[]]
    target = []
    for i in range(len(lst)):
        for p in combo(lst[i+1:], n-1):
            target.append([lst[i]]+p)
    return target

def reverse(s): return "" if not s else s[-1] + reverse(s[:-1]);

gpa_calculator = lambda s: "{} GPA for {} is {}".format(s["name"], s["semester"], '{:.2f}'.format(sum(i["credit_hours"]*"FDCBA".index(i["grade"]) for i in s["courses"]) / sum(i["credit_hours"] for i in s["courses"])))

class Test:
    @classmethod
    def assert_equals(self, v1, v2, message=""):
        print(v1, '<>', v2)
        assert v1 == v2, message or 'two val not equal lol'

    @classmethod
    def assert_not_equals(self, v1, v2, message=""):
        print(v1, '<!>', v2)
        assert v1 != v2, message or 'two val not equal lol'

def maximum_items(prices, budget):
    budget = int(budget[1:])
    items = sorted(int(i[1:]) for i in prices)
    can_buy = 0
    for i in items:
        if budget - i < 0: break
        can_buy += 1
        budget -= i
    return can_buy if can_buy else "Not enough funds!"
	
Test.assert_equals(maximum_items(["$1", "$1", "$2"], "$3"), 2)
Test.assert_equals(maximum_items(["$10", "$7", "$2", "$60"], "$20"), 3)
Test.assert_equals(maximum_items(["$15", "$5", "$30", "$30", "$10"], "$2"), "Not enough funds!")
Test.assert_equals(maximum_items(["$99", "$8"], "$9"), 1)
Test.assert_equals(maximum_items(["$85", "$88", "$72", "$77", "$53"], "$56"), 1)
Test.assert_equals(maximum_items(["$12", "$2", "$49", "$21", "$76", "$64"], "$37"), 3)
Test.assert_equals(maximum_items(["$3", "$17", "$12", "$98", "$12", "$91", "$41", "$73"], "$116"), 5)
Test.assert_equals(maximum_items(["$18", "$16", "$32", "$30", "$43", "$80", "$13"], "$86"), 4)
Test.assert_equals(maximum_items(["$20", "$11", "$8", "$59", "$64", "$36", "$41", "$99", "$98"], "$357"), 8)
Test.assert_equals(maximum_items(["$12", "$98", "$56", "$88"], "$489"), 4)
Test.assert_equals(maximum_items(["$12"], "$26"), 1)
Test.assert_equals(maximum_items(["$65", "$78", "$78", "$61", "$51", "$91", "$76", "$27", "$85", "$70"], "$64"), 1)
Test.assert_equals(maximum_items(["$28", "$64"], "$404"), 2)
Test.assert_equals(maximum_items(["$69"], "$188"), 1)
Test.assert_equals(maximum_items(["$59", "$99", "$59", "$90", "$75", "$19", "$36", "$56", "$79", "$5"], "$74"), 3)
Test.assert_equals(maximum_items(["$73", "$7", "$75", "$33", "$7", "$95", "$11"], "$463"), 7)
Test.assert_equals(maximum_items(["$58", "$64", "$85", "$21", "$91", "$1"], "$333"), 6)
Test.assert_equals(maximum_items(["$89", "$7", "$27"], "$451"), 3)
Test.assert_equals(maximum_items(["$10", "$63", "$25", "$2", "$10", "$59", "$71", "$60", "$88"], "$129"), 5)
Test.assert_equals(maximum_items(["$23", "$82", "$75", "$17", "$67", "$67", "$95", "$48", "$15"], "$185"), 5)
Test.assert_equals(maximum_items(["$86", "$22", "$92", "$8", "$44", "$97"], "$102"), 3)
Test.assert_equals(maximum_items(["$16"], "$136"), 1)
Test.assert_equals(maximum_items(["$37", "$46", "$68", "$7", "$75", "$53", "$79"], "$20"), 1)
Test.assert_equals(maximum_items(["$71", "$36", "$5", "$56", "$33", "$66", "$91", "$49"], "$120"), 3)
Test.assert_equals(maximum_items(["$43", "$70", "$25", "$100", "$47", "$95", "$8"], "$66"), 2)
Test.assert_equals(maximum_items(["$70", "$11", "$87", "$65", "$6", "$9", "$63", "$55", "$90", "$95"], "$177"), 5)
Test.assert_equals(maximum_items(["$24", "$90", "$100", "$31", "$99"], "$287"), 4)
Test.assert_equals(maximum_items(["$34", "$62", "$62", "$98", "$100"], "$101"), 2)
Test.assert_equals(maximum_items(["$59", "$90", "$97", "$34", "$31", "$37", "$31", "$97", "$52", "$70"], "$224"), 5)
Test.assert_equals(maximum_items(["$29", "$71", "$23", "$27", "$46", "$33"], "$100"), 3)
Test.assert_equals(maximum_items(["$34", "$6"], "$263"), 2)
Test.assert_equals(maximum_items(["$36", "$34", "$74", "$90", "$14", "$21", "$96", "$24", "$67"], "$306"), 7)
Test.assert_equals(maximum_items(["$78", "$83"], "$239"), 2)
Test.assert_equals(maximum_items(["$6", "$8", "$67", "$64"], "$349"), 4)
Test.assert_equals(maximum_items(["$95", "$59", "$58", "$28", "$82", "$38", "$65", "$33", "$29"], "$247"), 6)
Test.assert_equals(maximum_items(["$57", "$97", "$47", "$91", "$70", "$78"], "$440"), 6)
Test.assert_equals(maximum_items(["$45"], "$319"), 1)
Test.assert_equals(maximum_items(["$5", "$89", "$78", "$73", "$44", "$93", "$57", "$80"], "$402"), 6)
Test.assert_equals(maximum_items(["$1", "$26", "$54", "$12", "$5", "$61"], "$47"), 4)
Test.assert_equals(maximum_items(["$16", "$50"], "$331"), 2)
Test.assert_equals(maximum_items(["$6", "$51"], "$88"), 2)
Test.assert_equals(maximum_items(["$74", "$91"], "$493"), 2)
Test.assert_equals(maximum_items(["$51", "$81", "$64", "$51"], "$47"), "Not enough funds!")
Test.assert_equals(maximum_items(["$32", "$60", "$12", "$93", "$82"], "$242"), 4)
Test.assert_equals(maximum_items(["$92", "$55", "$35", "$78", "$1"], "$421"), 5)
Test.assert_equals(maximum_items(["$46", "$41", "$47", "$52", "$99", "$62", "$50", "$62", "$65", "$38"], "$5"), "Not enough funds!")
Test.assert_equals(maximum_items(["$33", "$4", "$4"], "$475"), 3)
Test.assert_equals(maximum_items(["$78", "$11", "$37", "$95", "$60", "$11", "$53", "$58", "$97"], "$231"), 6)
Test.assert_equals(maximum_items(["$20", "$69", "$46", "$91", "$42", "$49", "$54", "$44", "$96"], "$476"), 8)
Test.assert_equals(maximum_items(["$60", "$42", "$93", "$47", "$67"], "$478"), 5)
Test.assert_equals(maximum_items(["$81", "$14", "$12", "$89", "$69"], "$377"), 5)
Test.assert_equals(maximum_items(["$16", "$67", "$76", "$78", "$72", "$19"], "$288"), 5)
Test.assert_equals(maximum_items(["$47", "$55", "$27", "$73", "$72"], "$461"), 5)