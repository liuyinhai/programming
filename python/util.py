#!/usr/bin/python
#coding=gb18030

import os, sys

def b2q(ustr):
    return ''.join(unichr(0x3000 if c == 0x0020 else c+0xfee0 if 0x0020 < c < 0x007e else c) for c in map(ord, ustr))

def q2b(ustr):
    return ''.join(unichr(0x0020 if c == 0x3000 else c-0xfee0 if 0xff00 < c < 0xff80 else c) for c in map(ord, ustr))

if __name__ == "__main__":
    pass
