def f(x):
    return 43 * x - 180


def modified_graphical_method():

   
    # Phase 1: Scan ทีละ 1 เพื่อหาช่วงที่มีคำตอบ
    for x in range(0, 11):  # x = 0, 1, 2, ..., 10
        y = f(x)
        print(f"x = {x}, f(x) = {y}")

        # ตรวจสอบว่าเจอการเปลี่ยนเครื่องหมายหรือไม่
        if x > 0:
            prev_y = f(x - 1)
            if prev_y * y <= 0:
                # พบช่วงที่มีคำตอบ
                y_start = x - 1
                z_end = x    
                break

    # Phase 2: Scan ทีละ 0.000001 ในช่วงที่พบ
    step = 0.000001
    x = y_start
    closest_x = x
    closest_y = f(x)

    while x <= z_end:
        y = f(x)

        # หาค่าที่ใกล้ 0 มากที่สุด
        if abs(y) < abs(closest_y):
            closest_x = x
            closest_y = y
            
        # ถ้าพบค่าที่ใกล้ 0 มากพอ
        if abs(y) < 1e-10:
            print(f"Found accurate solution: x = {x:.6f}, f(x) = {y:.10f}")
            break

        x += step


    print(f"\nClosest: x = {closest_x:.6f}")
    print(f"f({closest_x:.6f}) = {closest_y:.10f}")


    return closest_x

# เรียกใช้งาน
modified_graphical_method()