class Solution:
    def isValidAscii(self, c):
        ac = ord(c)
        return (ac >= 48 and ac <= 56) or \
               (ac >= 65 and ac <= 70) or \
               (ac >= 97 and ac <= 102)

    def validIPAddress(self, IP):
        """
        :type IP: str
        :rtype: str
        """
        if '.' in IP:
            l = IP.split('.')
            if len(l) != 4: return 'Neither'
            for item in l:
                if item and (len(item) > 1 and (item[0] == '0' or item[0] == '-')): return 'Neither'
                try:
                    num = int(item)
                except:
                    return 'Neither'
                if num > 255 or num < 0: return 'Neither'
            return 'IPv4'
        elif ':' in IP:
            l = IP.split(':')
            if len(l) != 8: return 'Neither'
            for item in l:
                if len(item) > 4 or len(item) == 0: return 'Neither'
                for c in item:
                    if not self.isValidAscii(c): return 'Neither'

            return 'IPv6'
        return 'Neither'


def main():
    # IP = '2001:0db8:85a3:0:0:8A2E:0370:7334:' Neither
    # IP = '2001:db8:85a3:0::8a2E:0370:7334' Neither
    IP = '15.16.-0.1'
    s = Solution()
    print (s.validIPAddress(IP))


main()
