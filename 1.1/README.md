# 1.1操作系统上的程序
1. C程序是一个栈帧的状态机
- 状态 = `stack frame` 的列表 (每个 frame 有 PC) + 全局变量
- 初始状态 = `main(argc, argv)`, 全局变量初始化
- 迁移 = 执行 `top stack frame PC` 的语句; `PC++`
- 函数调用 = `push frame (frame.PC = 入口)`
- 函数返回 = `pop frame`

2. 汇编程序是一个寄存器和内存的状态机
- 状态 = 内存  + 寄存器 
- 初始状态:
    `ld-linux-x86-64.so`加载了 libc  
    之后 libc 完成了自己的初始化  
    RTFM: libc startup on Hurd  
    `main()` 的开始/结束并不是整个程序的开始/结束  
- 迁移 = 执行一条指令
- C=compile(S)

3. 操作系统中:程序 = 计算 + syscall

4. 计算机系统中不存在玄学
