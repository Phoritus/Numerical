def nth_root(x, n):
    
    # กรณีพิเศษ
    if x == 0:
        return 0
    if x == 1:
        return 1
    if n == 1:
        return x

    # ฟังก์ชัน f(r) = r^n - x
    def f(r):
        return r ** n - x

    # หา xl และ xr ระหว่าง 0 ถึง 1000000
    xl = None
    xr = None
    
    # วิธีที่ 1: ใช้ binary search หา xl (ค่าที่ f(xl) < 0)
    low = 0.0
    high = 1000000.0
    
    while low <= high:
        mid = (low + high) / 2
        if f(mid) < 0:
            xl = mid
            low = mid + 0.1
        else:
            high = mid - 0.1
    
    # วิธีที่ 2: ใช้ binary search หา xr (ค่าที่ f(xr) > 0)
    low = xl if xl else 0.0
    high = 1000000.0
    
    while low <= high:
        mid = (low + high) / 2
        if f(mid) > 0:
            xr = mid
            high = mid - 0.1
        else:
            low = mid + 0.1
    
    # วิธีที่ 3: หากไม่เจอ ใช้การสแกนทีละ 1
    if xl is None or xr is None:
        for test_val in range(0, 1000001):
            f_val = f(test_val)
            
            if f_val < 0:
                xl = float(test_val)
            elif f_val > 0 and xl is not None:
                xr = float(test_val)
                break
    
    # ตรวจสอบว่าเจอขอบเขตหรือไม่
    if xl is None or xr is None:
        print(f"Could not find valid bounds xl and xr between 0 and 1000000")
        return None

    print(f"Found bounds: xl = {xl:.6f}, xr = {xr:.6f}")

    # ใช้ bisection method หาคำตอบ
    low = xl
    high = xr
    
    while high - low > 0.0001:  # ความแม่นยำ 4 ทศนิยม
        mid = (low + high) / 2
        
        f_low = f(low)
        f_mid = f(mid)
        
        if f_low * f_mid < 0:
            # Root อยู่ระหว่าง low และ mid
            high = mid
        else:
            # Root อยู่ระหว่าง mid และ high
            low = mid

    return (low + high) / 2

x, n = float(input()), int(input())

result = nth_root(x, n)
print(f"\n{x}^(1/{n}) = {result:.4f}")