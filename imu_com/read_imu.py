def append2(i):
    if len(i) < 2:
        return "0" + str(i)
    else: return i

def to_hex(arr):
    return [append2(hex(i)[2:]) for i in arr]

def read_n(ser, n):
    bytes_arr = [bytes_arr.append(to_hex(ser.read())) for i in range(n)]
    return bytes_arr

def checksum(bytes_arr):
    cs = 0
    for b in bytes_arr:
        temp = cs
        binary = format(b & 0xFF, '08b')
        print("binary:", binary)
        bitwise_not = ''.join(['1' if c == '0' else '0' for c in binary])
        # bitwise_not = ''.join([str(int(not bool(c))) for c in binary])
        print("bitwise_not:", bitwise_not)
        cs += int(bitwise_not, 2) + 1
        cs %= 256
        print(f"{format(temp & 0xFF, '08b')} - {binary} = {format(cs & 0xFF, '08b')} + {bitwise_not} + 1 = {format(cs & 0xFF, '08b')}")
    return cs

def count(ser, period):
    count = 0
    while True:
        _ = ser.read()
        count += 1
        if count % period == 0:
            print("Received", count, "bytes")
