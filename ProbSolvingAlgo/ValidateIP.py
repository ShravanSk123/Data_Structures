# validates ipv4 and ipv6 addresses
import re

def isIPV4(s):
    try:
        return str(int(s)) == s and 0 <= int(s) <= 255
    except:
        return False
    
def isIPV6(s):
    if len(s)>4 or re.match("\W",s): # "\W" is used for special characters
        return False
    try:
        int(s,16)
        return True
    except:
        return False

# main
IP = input()
ipv4 = IP.split('.')
ipv6 = IP.split(':')

if len(ipv4)==4 and all(isIPV4(n) for n in ipv4):
    print("IPv4")
elif len(ipv6)==8 and all(isIPV6(n) for n in ipv6):
    print("IPv6")
else:
    print("Neither")
