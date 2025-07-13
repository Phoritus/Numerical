def f(x):

    return x ** 4 - 13


def bisection_method(a, b, tolerance=1e-6):    

    iteration = 0
    prev_c = None

    while True:
        iteration += 1
        c = (a + b) / 2
        fc = f(c)

        # คำนวณ error
        if prev_c is not None:
            error = abs(c - prev_c)
        else:
            error = float('inf')

        # ตรวจสอบเงื่อนไขการหยุด (ไม่มีการเปลี่ยนแปลงจุดทศนิยม 6 ตำแหน่ง)
        if prev_c is not None and abs(c - prev_c) < tolerance:
            break

        # ตรวจสอบว่าได้คำตอบแล้วหรือไม่
        if abs(fc) < tolerance:
            print(f"Found root: c = {c:.6f}, f(c) = {fc:.10f}")
            break

        # อัปเดตขอบเขต
        if f(a) * fc < 0:
            b = c
        else:
            a = c

        prev_c = c

        # ป้องกันลูปไม่สิ้นสุด
        if iteration > 100:
            break

    print(f"f({c:.6f}) = {f(c):.10f}")
    print(f"Iterations: {iteration}")

    return c


result = bisection_method(1.5, 2.0)