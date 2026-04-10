# 函数开始时间和结束时间

import datetime
import time
from functools import wraps

def timer_log(func):
    """
    一个装饰器，用于记录函数的执行开始和结束时间。
    """
    # @wraps(func) 是一个重要的辅助装饰器，
    # 它的作用是将被装饰函数（如下面的 func1）的元信息（如函数名__name__、文档字符串__doc__等）
    # 复制到包装函数 wrapper 上，否则函数名会变成'wrapper'。
    @wraps(func)
    def wrapper(*args, **kwargs):
        """
        这是包装函数，它会执行实际的日志记录和函数调用。
        """
        # 1. 记录并打印进入函数的时间
        start_time_str = datetime.datetime.now().strftime('%H:%M:%S')
        print(f"{start_time_str} start {func.__name__}")

        # 使用 try...finally 结构确保无论函数是否成功执行，
        # “离开”日志总能被打印出来。
        try:
            # 2. 调用原始的、被装饰的函数
            # *args, **kwargs 用来接收并传递任意数量的位置参数和关键字参数
            result = func(*args, **kwargs)
            return result
        finally:
            # 3. 记录并打印离开函数的时间
            end_time_str = datetime.datetime.now().strftime('%H:%M:%S')
            print(f"{end_time_str} end {func.__name__}")

    return wrapper

# --- 下面是使用装饰器的示例 ---

@timer_log
def func1(sleep_time=2):
    """
    一个模拟耗时操作的函数。
    """
    print(f"==> func1 开始执行，将休眠 {sleep_time} 秒...")
    time.sleep(sleep_time)
    print("==> func1 执行完毕。")
    return "Function 1 Finished"

@timer_log
def func2(a, b):
    """
    一个模拟快速计算的函数。
    """
    print("==> func2 开始执行，进行加法计算...")
    result = a + b
    print("==> func2 执行完毕。")
    return f"计算结果是: {result}"

# 主程序入口
if __name__ == "__main__":
    print("--- 开始运行程序 ---\n")
    
    # 调用被装饰的函数 func1
    func1_result = func1(1)
    print(f"func1 的返回值: {func1_result}\n")
    
    # 调用被装饰的函数 func2
    func2_result = func2(10, 20)
    print(f"func2 的返回值: {func2_result}\n")

    print("--- 程序运行结束 ---")


'''
--- 开始运行程序 ---

20:00:45 start func1
==> func1 开始执行，将休眠 1 秒...
==> func1 执行完毕。
20:00:46 end func1
func1 的返回值: Function 1 Finished

20:00:46 start func2
==> func2 开始执行，进行加法计算...
==> func2 执行完毕。
20:00:46 end func2
func2 的返回值: 计算结果是: 30

--- 程序运行结束 ---
'''