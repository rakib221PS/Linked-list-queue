import ctypes

magical = ctypes.CDLL("./libmagical.so")

magical.f()

magical.fact.argtypes = [ctypes.c_int]
magical.fact.rettype = ctypes.c_int

ret = magical.fact(10)

print(ret)
