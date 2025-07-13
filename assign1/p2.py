def bisection_method(func, a, b, tolerance=1e-6):
  
    # ตรวจสอบขอบเขต
    fa = func(a)
    fb = func(b)
    
    if fa * fb > 0:
        raise ValueError("Function values at the endpoints must have opposite signs.")
    
    iteration = 0
    prev_c = None
    
    while True:
        iteration += 1
        c = (a + b) / 2
        fc = func(c)
        
        # เงื่อนไขการหยุด
        if prev_c is not None and abs(c - prev_c) < tolerance:
            break
            
        if abs(fc) < tolerance:
            break
        
        # อัปเดตขอบเขต
        if func(a) * fc < 0:
            b = c
        else:
            a = c
            
        prev_c = c
        
        if iteration > 100:
            break
    
    return c
def f1(x):
    return x ** 4 - 13

result1 = bisection_method(f1, 1.5, 2.0)  # x⁴ - 13 = 0
print(f"Root of x⁴ - 13 = 0: {result1:.6f}")