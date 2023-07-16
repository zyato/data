# 0. 知识点

1. Go 不需要在语句或声明后面使用分号结尾，除非有多个语句或声明出现在同一行。事实上，跟在特定符号后面的换行符被转换为分号，在什么地方进行换行会影响对 Go 代码的解析。

    - “{”符号必须和关键字 func 在同一行，不能独自成行

    - “{”在 `for` 循环中，只有 `for {}` 这种格式，“{”可以独自成行，否则会编译报错

    - **在循环中和分支结构中，大括号是必须的**

    - 在 `x + y` 这个表达式中，换行符可以在 `+` 操作符的后面，但是不能在 `+` 操作符的前面

        ```go
        // 这个表达式正确
        a := 1 +
        2
        // 这个表达式报错
        b := 1 
        + 2
        ```

2. 习惯上，在一个包声明前，使用注释对其进行描述

3. 自增语句。`i++`、`i--`是语句，而不像 C 语言一样是表达式，所以 `j = i++` 是不合法的，**并且，仅支持后缀，所以 `--i`是不合法的**

# 1. Go 命令

`go build`：编译 Go 程序

`go build -o "xx.exe"` ：编译成 "xx.exe" 文件

`go run main.go `：像执行脚本一样执行 main.go 文件

`go install`：先编译后拷贝

# 2. Go 语言文件基础语法

1. 存放 Go 源代码的文件名后缀是 `.go`

2. 文件第一行：package 关键字声明包名

3. 如果要编译可执行文件，必须要有 main 包和 main 函数（入口函数）

4. 函数外的每个语句都必须以关键字开始（var、const、func等）

    ```go
    var age int // 没问题
    age = 18 // 报错，虽然 age 已声明，但不是以关键字开头
    name := "yato" // 报错，不是以关键字开头
    var birthday int = 2021 // 没问题
    ```

5. 函数内部定义的变量必须使用，外部定义的是全局变量，没有这个要求

6. 左大括号 `{` 不能新起一行，要放在语句末尾

# 3. 标识符和关键字

## 3.1 标识符

​	在编程语言中标识符就是程序员定义的具有特殊意义的词，比如变量名、常量名、函数名等等。 Go 语言中标识符由字母数字和`_`(下划线）组成，并且只能以字母和`_`开头。 举几个例子：`abc`, `_`, `_123`, `a123`。

## 3.2 关键字

关键字是指编程语言中预先定义好的具有特殊含义的标识符。 关键字和保留字都不能用作变量名。

Go语言中有25个关键字：

```go
    break        default      func         interface    select
    case         defer        go           map          struct
    chan         else         goto         package      switch
    const        fallthrough  if           range        type
    continue     for          import       return       var
```

此外，Go语言中还有37个保留字。

```go
    Constants:    true  false  iota  nil

        Types:    int  int8  int16  int32  int64  
                  uint  uint8  uint16  uint32  uint64  uintptr
                  float32  float64  complex128  complex64
                  bool  byte  rune  string  error

    Functions:   make  len  cap  new  append  copy  close  delete
                 complex  real  imag
                 panic  recover
```

# 4. 变量

## 4.1 变量的声明方式

1. `var 变量名 变量类型`：只声明

2. `var name2 = "啊啊啊"`：声明且赋值（自动推断类型）

3. `name3 := "啊啊啊" `（自动推断类型）**只能在函数内部使用**

4. 批量声明（同时可以赋值）

    ```go
    var (
    	a string
           b int = 3
           c bool
           d float32
    )
    ```

## 4.2 变量的初始化

> Go语言在声明变量的时候，会自动对变量对应的内存区域进行初始化操作。每个变量会被初始化成其类型的默认值，例如： 整型和浮点型变量的默认值为`0`。 字符串变量的默认值为`空字符串`。 布尔型变量默认为`false`。 切片、函数、指针变量的默认为`nil`。

当然我们也可在声明变量的时候为其指定初始值。变量初始化的标准格式如下：

```go
var 变量名 类型 = 表达式
```

举个例子：

```go
var name string = "Q1mi"
var age int = 18
```

或者一次初始化多个变量

```go
var name, age = "Q1mi", 20
```

## 4.3 类型推导

有时候我们会将变量的类型省略，这个时候编译器会**根据等号右边的值**来推导变量的类型完成初始化。

```go
var name = "Q1mi"
var age = 18
```

## 4.4 短变量声明

**在函数内部**，可以使用更简略的 `:=` 方式声明并初始化变量。

```go
package main

import (
	"fmt"
)
// 全局变量m
var m = 100

func main() {
	n := 10
	m := 200 // 此处声明局部变量m
	fmt.Println(m, n)
}
```

## 4.5 匿名变量（哑元变量）

- 在使用多重赋值时，如果想要忽略某个值，可以使用`匿名变量（anonymous variable）`。 

- 匿名变量用一个下划线`_`表示。

- 可以用 `_` 来接收这个值，且 `_`是只写的，不能读

- 匿名变量不占用命名空间，不会分配内存，所以匿名变量之间不存在重复声明。 

# 5. 常量

> 相对于变量，常量是恒定不变的值，多用于定义程序运行期间不会改变的那些值。 常量的声明和变量声明非常类似，只是把`var`换成了`const`，常量在定义的时候必须赋值。

## 5.1 常量的声明方式

1. const PI float64 = 3.1415926

2. const PI = 3.1415926

3. 多个常量也可以一起声明：

    ```go
    const (
        pi = 3.1415
        e = 2.7182
    )
    ```

    const同时声明多个常量时，如果省略了值则表示和上面一行的值相同。 例如：

    ```go
    const (
        n1 = 100
        n2
        n3
    )
    ```

    上面示例中，常量`n1`、`n2`、`n3`的值都是100。

## 5.2 iota 实现枚举

三个要点：

1. iota 是 go 语言的常量计数器，只能在常量的表达式中使用

2. iota 在 const 关键字出现时将被重置为 0

3. const 中每新增一行常量声明，iota 的值增加 1（iota 可理解为 const 语句块的行索引）

4. 举个例子：

    ```go
    const (
    		n1 = iota //0
    		n2        //1
    		n3        //2
    		n4        //3
    	)
    ```

# 6. 基本数据类型

## 6.1 整型

- 无符号整型：uint8、uint16、uint32、uint64
- 有符号整型：int8、int16、int32、int64
- uint 和 int：取决于操作系统，64 位的操作系统对应 uint64/int64；32位的操作系统对应 uint32/int32
- uintptr：无符号整型，用于存放一个指针

## 6.2 数字字面量语法（Number literals syntax）

Go1.13 版本之后引入了数字字面量语法，这样便于开发者以二进制、八进制或十六进制浮点数的格式定义数字，例如：

`v := 0b00101101`， 代表二进制的 101101，相当于十进制的 45。 `v := 0o377`，代表八进制的 377（其中 o 可以省略，但是 0 不可以省略），相当于十进制的 255。 `v := 0x1p-2`，代表十六进制的 1 除以 2²，也就是 0.25。

而且还允许我们用 `_` 来分隔数字，比如说： `v := 123_456` 表示 v 的值等于 123456。

我们可以借助fmt函数来将一个整数以不同进制形式展示。

```go
package main
 
import "fmt"
 
func main(){
	// 十进制
	var a int = 10
	fmt.Printf("%d \n", a)  // 10
	fmt.Printf("%b \n", a)  // 1010  占位符%b表示二进制
 
	// 八进制  以0开头
	var b int = 077
	fmt.Printf("%o \n", b)  // 77
 
	// 十六进制  以0x开头
	var c int = 0xff
	fmt.Printf("%x \n", c)  // ff
	fmt.Printf("%X \n", c)  // FF
}
```

## 6.3 浮点型

- float32 和 float64

- 默认是 float64,

- 定义 float32 类型变量的方式

    ```go
    var a float32 = 3.1415
    var b = float32(3.1415)
    c := float32(3.1415)
    ```

- float32 和 float64 之间不能做等值（==）判断，会报错（不匹配的类型）

- Go 语言不同类型之间不能做等值判断，不仅限于浮点类型

## 6.4 复数

complex128 和 complex64

复数有实部和虚部，complex64 的实部和虚部为 32 位，complex128 的实部和虚部为 64 位。

## 6.5 布尔值 bool

true 和 false

**注意：**

1. 布尔类型变量的默认值为`false`。
2. Go 语言中不允许将整型强制转换为布尔型.
3. 布尔型无法参与数值运算，也无法与其他类型进行转换。

## 6.6 字符串 string

> Go 语言中的字符串以原生数据类型出现，使用字符串就像使用其他原生数据类型（int、bool、float32、float64 等）一样。 Go 语言里的字符串的内部实现使用`UTF-8`编码。 字符串的值为`双引号(")`中的内容，可以在 Go 语言的源码中直接添加非ASCII码字符，例如：
>
> ```go
> s1 := "hello"
> s2 := "你好"
> ```

##### 6.6.1 字符串中的转义字符

| 转义符 |                含义                |
| :----: | :--------------------------------: |
|  `\r`  |         回车符（返回行首）         |
|  `\n`  | 换行符（直接跳到下一行的同列位置） |
|  `\t`  |               制表符               |
|  `\'`  |               单引号               |
|  `\"`  |               双引号               |
|  `\\`  |               反斜杠               |

举个例子，我们要打印一个Windows平台下的一个文件路径：

```go
package main
import (
    "fmt"
)
func main() {
    fmt.Println("str := \"c:\\Code\\lesson1\\go.exe\"")
}
```

##### 6.6.2 多行字符串

Go 语言中要定义一个多行字符串时，就必须使用`反引号`字符：

```go
s1 := `第一行
第二行
第三行
`
fmt.Println(s1)
```

反引号间换行将被作为字符串中的换行，但是所有的转义字符均无效，文本将会原样输出。

##### 6.6.3 字符串的常用操作

|                方法                 |      介绍      |
| :---------------------------------: | :------------: |
|              len(str)               |     求长度     |
|           +或fmt.Sprintf            |   拼接字符串   |
|            strings.Split            |      分割      |
|          strings.contains           |  判断是否包含  |
| strings.HasPrefix,strings.HasSuffix | 前缀/后缀判断  |
| strings.Index(),strings.LastIndex() | 子串出现的位置 |
| strings.Join(a[]string, sep string) |    join操作    |

## 6.7 byte 和 rune 类型

> 组成每个字符串的元素叫做“字符”，可以通过遍历或者单个获取字符串元素获得字符。 字符用单引号（’）包裹起来，如：
>
> ```go
> var a := '中'
> var b := 'x'
> ```

### 6.7.1 字符类型分类

​	Go 语言的字符有以下两种：

1. `uint8`类型，或者叫 byte 型，代表了`ASCII码`的一个字符。
2. `rune`类型，代表一个 `UTF-8字符`。

3. 当需要处理中文、日文或者其他复合字符时，则需要用到`rune`类型。`rune`类型实际是一个`int32`。

    Go 使用了特殊的 rune 类型来处理 Unicode，让基于 Unicode 的文本处理更为方便，也可以使用 byte 型进行默认字符串处理，性能和扩展性都有照顾。

    ```go
    // 遍历字符串
    func traversalString() {
    	s := "hello沙河"
    	for i := 0; i < len(s); i++ { //byte
    		fmt.Printf("%v(%c) ", s[i], s[i])
    	}
    	fmt.Println()
    	for _, r := range s { //rune
    		fmt.Printf("%v(%c) ", r, r)
    	}
    	fmt.Println()
    }
    ```

    输出：

    ```go
    104(h) 101(e) 108(l) 108(l) 111(o) 230(æ) 178(²) 153() 230(æ) 178(²) 179(³) 
    104(h) 101(e) 108(l) 108(l) 111(o) 27801(沙) 27827(河) 
    ```

    因为 UTF8 编码下一个中文汉字由 3~4 个字节组成，所以我们不能简单的按照字节去遍历一个包含中文的字符串，否则就会出现上面输出中第一行的结果。

    字符串底层是一个 byte 数组，所以可以和`[]byte`类型相互转换。字符串是不能修改的 字符串是由 byte 字节组成，所以字符串的长度是 byte 字节的长度。 rune 类型用来表示 utf8 字符，一个 rune 字符由一个或多个 byte 组成。

### 6.7.2 修改字符串

​	要修改字符串，需要先将其转换成`[]rune`或`[]byte`，完成后再转换为`string`。无论哪种转换，都会重新分配内存，并复制字节数组。

```go
func changeString() {
	s1 := "big"
	// 强制类型转换
	byteS1 := []byte(s1)
	byteS1[0] = 'p'
	fmt.Println(string(byteS1))

	s2 := "白萝卜"
	runeS2 := []rune(s2)
	runeS2[0] = '红'
	fmt.Println(string(runeS2))
}
```

## 6.8 类型转换

Go语言中只有强制类型转换，没有隐式类型转换。该语法只能在两个类型之间支持相互转换的时候使用。

强制类型转换的基本语法如下：

```bash
T(表达式)
```

其中，T表示要转换的类型。表达式包括变量、复杂算子和函数返回值等.

比如计算直角三角形的斜边长时使用math包的Sqrt()函数，该函数接收的是float64类型的参数，而变量a和b都是int类型的，这个时候就需要将a和b强制类型转换为float64类型。

```go
func sqrtDemo() {
	var a, b = 3, 4
	var c int
	// math.Sqrt()接收的参数是float64类型，需要强制转换
	c = int(math.Sqrt(float64(a*a + b*b)))
	fmt.Println(c)
}
```



# 7. 流程控制

## 7.1 if 判断

> Go 语言规定与`if`匹配的左括号`{`必须与`if和表达式`放在同一行，`{`放在其他位置会触发编译错误。 同理，与`else`匹配的`{`也必须与`else`写在同一行，`else`也必须与上一个`if`或`else if`右边的大括号在同一行。

```go
if 条件表达式 {
    ...
} else if  条件表达式 {
    ...
} else {
    ...
}
```

**if 条件判断特殊写法**

​	if条件判断还有一种特殊的写法，可以在 if 表达式之前添加一个执行语句，再根据变量值进行判断，举个例子：

```go
func ifDemo2() {
	if score := 65; score >= 90 {
		fmt.Println("A")
	} else if score > 75 {
		fmt.Println("B")
	} else {
		fmt.Println("C")
	}
}
```

此时，在 if 的表达式之前定义了一个 score 变量，这个变量的作用域只在 if...else if...else 这整个表达式内有效。可以降低变量的冲突率。

## 7.2 for 循环

> Go 语言中的所有循环类型均可使用 for 关键字来完成
>
> for 循环可以通过 break、goto、return、panic 语句强制退出循环

for 循环的四种使用方式

1. 类似于 java 的 for

    ```go
    for i := 0; i < 10; i++ {
        ...
    }
    ```

2. 类似于 java 的 while

    ```go
    i := 0
    for i < 10 {
        ...
        i++
    }
    ```

3. 无限循环

    ```go
    for {
        ...
    }
    ```

4. for ... range，用于遍历数组、切片、字符串、map 及通道（channel）

    ```go
    s := "abc"
    for index, character := range s {
        ...
    }
    ```

     通过 for range 遍历的返回值有一下规律：

    - 数组、切片、字符串返回索引和值
    - map 返回键和值
    - 通道只返回通道内的值

## 7.3 switch case语句

> 使用`switch`语句可方便地对大量的值进行条件判断。
>
> Go 语言规定每个 switch 只能有一个 default 分支
>
> fallthrough 语法可以执行满足条件的 case 的下一个 case（无论下一个 case 是否满足条件）

### 7.3.1 分支是值的方式

```go
func switchDemo1() {
	finger := 3
	switch finger {
	case 1:
		fmt.Println("大拇指")
	case 2:
		fmt.Println("食指")
	case 3:
		fmt.Println("中指")
	case 4:
		fmt.Println("无名指")
	case 5:
		fmt.Println("小拇指")
	default:
		fmt.Println("无效的输入！")
	}
}
```

一个分支可以有多个值，多个 case 值中间使用英文逗号分隔

switch 可以在值之前加一个执行语句，类似于 if。例如 switch n := 7; n {}

```go
func testSwitch3() {
	switch n := 7; n {
	case 1, 3, 5, 7, 9:
		fmt.Println("奇数")
	case 2, 4, 6, 8:
		fmt.Println("偶数")
	default:
		fmt.Println(n)
	}
}
```

### 7.3.2 分支是表达式的方式

**此时 switch 语句后面不需要再跟判断变量**

```go
func switchDemo4() {
	age := 30
	switch {
	case age < 25:
		fmt.Println("好好学习吧")
	case age > 25 && age < 35:
		fmt.Println("好好工作吧")
	case age > 60:
		fmt.Println("好好享受吧")
	default:
		fmt.Println("活着真好")
	}
}
```

## 7.4 goto 跳转到指定标签

> `goto`语句通过标签进行代码间的无条件跳转。`goto`语句可以在快速跳出循环、避免重复退出上有一定的帮助。Go语言中使用`goto`语句能简化一些代码的实现过程。 

```go
func gotoDemo2() {
	for i := 0; i < 10; i++ {
		for j := 0; j < 10; j++ {
			if j == 2 {
				// 设置退出标签
				goto breakTag
			}
			fmt.Printf("%v-%v\n", i, j)
		}
	}
	return
	// 标签
breakTag:
	fmt.Println("结束for循环")
}
```

## 7.5 break 跳出循环

> `break`语句可以结束`for`、`switch`和`select`的代码块。
>
> `break`语句还可以在语句后面添加标签，表示退出某个标签对应的代码块，标签要求必须定义在对应的`for`、`switch`和 `select`的代码块上。

```go
func breakDemo1() {
BREAKDEMO1:
	for i := 0; i < 10; i++ {
		for j := 0; j < 10; j++ {
			if j == 2 {
				break BREAKDEMO1
			}
			fmt.Printf("%v-%v\n", i, j)
		}
	}
	fmt.Println("...")
}
```

## 7.6 continue 继续下次循环

> `continue`语句可以结束当前循环，开始下一次的循环迭代过程，仅限在`for`循环内使用。
>
> 在 `continue`语句后添加标签时，表示继续标签对应的下次循环。

```go
func continueDemo() {
forloop1:
	for i := 0; i < 5; i++ {
		// forloop2:
		for j := 0; j < 5; j++ {
			if i == 2 && j == 2 {
                	    // 注意，这里执行后，会直接跳过内层循环，继续外层循环的下次循环
				continue forloop1
			}
			fmt.Printf("%v-%v\n", i, j)
		}
	}
}
```

# 8. 运算符

> Go 语言内置的运算符有：
>
> 1. 算术运算符
> 2. 关系运算符
> 3. 逻辑运算符
> 4. 位运算符
> 5. 赋值运算符

## 8.1 算术运算符

+、-、*、/、% 分别对应加、减、乘、除、取余

**注意，++ 和 -- 在 Go 语言中是单独的语句，并不是运算符，而且没有返回值，只能单独使用。`b := a++` 这种操作会报错**

## 8.2 关系运算符

==、!=、>、>=、<、<=

## 8.3 逻辑运算符

&&、||、!

应该会有短路现象

## 8.4 位运算符

**位运算符对整数在内存中的二进制位进行操作**

| 运算符 |                             描述                             |
| :----: | :----------------------------------------------------------: |
|   &    |   参与运算的两数各对应的二进位相与。 （两位均为 1 才为 1）   |
|   \|   | 参与运算的两数各对应的二进位相或。 （两位有一个为 1 就为 1） |
|   ^    | 参与运算的两数各对应的二进位相异或，当两对应的二进位相异时，结果为 1。 （两位不一样则为1） |
|   <<   | 左移 n 位就是乘以 2 的 n 次方。 “a<<b”是把 a 的各二进位全部左移 b 位，高位丢弃，低位补 0。 |
|   >>   | 右移 n 位就是除以 2 的 n 次方。 “a>>b”是把 a 的各二进位全部右移 b 位。 |

## 8.5 赋值运算符

=、+=、-=、*=、/=、%=、<<=、>>=、&=、|=、^=



# 9. 数组

> 数组是同一种数据类型元素的集合。 在Go语言中，数组从声明时就确定，使用时可以修改数组成员，但是数组大小不可变化。 

## 9.1 数组的定义

`var 数组变量名 [元素数量]数组类型`

比如：`var arr [5]int`，数组的长度必须是常量，并且长度是数组类型的一部分。一旦定义，长度不能变。

`[5]int`和`[10]int`是不同的类型

```go
var a [3]int
var b [4]int
a == b // 不可以这么做，因为此时 a 和 b 是不同的类型
```

数组可以通过下标进行访问，下标是从`0`开始，最后一个元素下标是：`len-1`，访问越界（下标在合法范围之外），则触发访问越界，会 panic。

## 9.2 数组的初始化

1. 初始化数组时可以使用初始化列表来设置数组元素的值

    ```go
    func main() {
    	var testArray [3]int                        //数组会初始化为 int 类型的零值
    	var numArray = [3]int{1, 2}                 //使用指定的初始值完成初始化，不够的设置为默认值
    	var cityArray = [3]string{"北京", "上海", "深圳"} //使用指定的初始值完成初始化
    	fmt.Println(testArray)                      //[0 0 0]
    	fmt.Println(numArray)                       //[1 2 0]
    	fmt.Println(cityArray)                      //[北京 上海 深圳]
    }
    ```

2. 按照上面的方法每次都要确保提供的初始值和数组长度一致，一般情况下我们可以让编译器根据初始值的个数自行推断数组的长度

    ```go
    func main() {
    	var testArray [3]int
    	var numArray = [...]int{1, 2}
    	var cityArray = [...]string{"北京", "上海", "深圳"}
    	fmt.Println(testArray)                          //[0 0 0]
    	fmt.Println(numArray)                           //[1 2]
    	fmt.Printf("type of numArray:%T\n", numArray)   //type of numArray:[2]int
    	fmt.Println(cityArray)                          //[北京 上海 深圳]
    	fmt.Printf("type of cityArray:%T\n", cityArray) //type of cityArray:[3]string
    }
    ```

3. 指定索引值的方式初始化数组，未指定的设置为默认值，数组长度为指定的索引的最大值加一

    ```go
    func main() {
    	a := [...]int{1: 1, 3: 5}
    	fmt.Println(a)                  // [0 1 0 5]
    	fmt.Printf("type of a:%T\n", a) //type of a:[4]int
    }
    ```

## 9.3 数组的遍历

两种方式

```go
func main() {
	var a = [...]string{"北京", "上海", "深圳"}
	// 方法1：for循环遍历
	for i := 0; i < len(a); i++ {
		fmt.Println(a[i])
	}
	// 方法2：for range遍历
	for index, value := range a {
		fmt.Println(index, value)
	}
}
```

## 9.4 多维数组

1. 二维数组的定义

    ```go
    func main() {
    	a := [3][2]string{
    		{"北京", "上海"},
    		{"广州", "深圳"},
    		{"成都", "重庆"},
    	}
    	fmt.Println(a) //[[北京 上海] [广州 深圳] [成都 重庆]]
    	fmt.Println(a[2][1]) //支持索引取值:重庆
    }
    ```

2. 二维数组的遍历

    ```go
    func main() {
    	a := [3][2]string{
    		{"北京", "上海"},
    		{"广州", "深圳"},
    		{"成都", "重庆"},
    	}
    	for _, v1 := range a {
    		for _, v2 := range v1 {
    			fmt.Printf("%s\t", v2)
    		}
    		fmt.Println()
    	}
    }
    ```

**注意，多维数组只有第一层可以使用 ... 来让编译器推导数组长度。**

```go
//支持的写法
a := [...][2]string{
	{"北京", "上海"},
	{"广州", "深圳"},
	{"成都", "重庆"},
}
//不支持多维数组的内层使用...
b := [3][...]string{
	{"北京", "上海"},
	{"广州", "深圳"},
	{"成都", "重庆"},
}
```

## 9.5 数组是值类型的

数组是值类型，赋值和传参会复制整个数组。因此改变副本的值，不会改变本身的值。

```go
func modifyArray(x [3]int) {
	x[0] = 100
}

func modifyArray2(x [3][2]int) {
	x[2][0] = 100
}
func main() {
	a := [3]int{10, 20, 30}
	modifyArray(a) //在modify中修改的是a的副本x
	fmt.Println(a) //[10 20 30]
	b := [3][2]int{
		{1, 1},
		{1, 1},
		{1, 1},
	}
	modifyArray2(b) //在modify中修改的是b的副本x
	fmt.Println(b)  //[[1 1] [1 1] [1 1]]
}
```

**注意：**

1. 数组支持 “==“、”!=” 操作符，因为内存总是被初始化过的，**要求比较的两数组必须是同一类型，[3]int 只能和 [3]int 类型的数组使用 == 或者 != 来比较**。
2. `[n]*T`表示指针数组，`*[n]T`表示数组指针 

# 10. 切片 slice

## 10.1 因子

因为数组的长度是固定的并且数组长度属于类型的一部分，所以数组有很多的局限性。

```go
func arraySum(x [3]int) int{
    sum := 0
    for _, v := range x{
        sum = sum + v
    }
    return sum
}
```

这个求和函数只能接受`[3]int`类型，其他的都不支持。 再比如，

```go
a := [3]int{1, 2, 3}
```

数组a中已经有三个元素了，我们不能再继续往数组a中添加新元素了。

## 10.2 切片的引入

- 切片（Slice）是一个拥有相同类型元素的可变长度的序列。它是基于数组类型做的一层封装。它非常灵活，支持自动扩容。

- 切片是一个引用类型，它的内部结构包含`地址`、`长度`和`容量`。切片一般用于快速地操作一块数据集合。

## 10.3 切片的定义

声明切片类型的基本语法如下：

```go
var name []T
```

其中，

- name：表示变量名
- T：表示切片中的元素类型

举个例子：

```go
func main() {
	// 声明切片类型
	var a []string              //声明一个字符串切片
	var b = []int{}             //声明一个整型切片并初始化
	var c = []bool{false, true} //声明一个布尔切片并初始化
	var d = []bool{false, true} //声明一个布尔切片并初始化
	fmt.Println(a)              //[]
	fmt.Println(b)              //[]
	fmt.Println(c)              //[false true]
	fmt.Println(a == nil)       //true
	fmt.Println(b == nil)       //false
	fmt.Println(c == nil)       //false
	// fmt.Println(c == d)   //切片是引用类型，不支持直接比较，只能和nil比较
}
```

**注意，切片是引用类型，不支持直接比较，只能和 nil 直接比较**

## 10.4 切片的长度和容量

1. 通过使用内置的 `len()` 函数求切片的长度
2. 通过使用内置的 `cap()` 函数求切片的容量

## 10.5 切片表达式

> 切片表达式从字符串、数组、指向数组或切片的指针构造子字符串或切片。它有两种变体：一种指定low和high两个索引界限值的简单的形式，另一种是除了low和high索引界限值外还指定容量的完整的形式。

### 10.5.1 简单切片表达式

切片的底层就是一个数组，所以我们可以基于数组通过切片表达式得到切片。 切片表达式中的`low`和`high`表示一个索引范围（左包含，右不包含），也就是下面代码中从数组a中选出`1<=索引值<4`的元素组成切片s，得到的切片`长度=high-low`，容量等于得到的切片的底层数组的容量。

```go
func main() {
	a := [5]int{1, 2, 3, 4, 5}
	s := a[1:3]  // s := a[low:high]
	fmt.Printf("s:%v len(s):%v cap(s):%v\n", s, len(s), cap(s))
}
```

输出：

```bash
s:[2 3] len(s):2 cap(s):4
```

为了方便起见，可以省略切片表达式中的任何索引。省略了`low`则默认为0；省略了`high`则默认为切片操作数的长度:

```go
a[2:]  // 等同于 a[2:len(a)]
a[:3]  // 等同于 a[0:3]
a[:]   // 等同于 a[0:len(a)]
```

**注意：**

对于数组或字符串，如果`0 <= low <= high <= len(a)`，则索引合法，否则就会索引越界（out of range）。

对切片再执行切片表达式时**（切片再切片），`high`的上限边界是切片的容量`cap(a)`，而不是长度**。**常量索引**必须是非负的，并且可以用 int 类型的值表示；对于数组或常量字符串，常量索引也必须在有效范围内。如果`low`和`high`两个指标都是常数，它们必须满足`low <= high`。如果索引在运行时超出范围，就会发生运行时`panic`。

```go
func main() {
	a := [5]int{1, 2, 3, 4, 5}
	s := a[1:3]  // s := a[low:high]
	fmt.Printf("s:%v len(s):%v cap(s):%v\n", s, len(s), cap(s))
	s2 := s[3:4]  // 索引的上限是cap(s)而不是len(s)
	fmt.Printf("s2:%v len(s2):%v cap(s2):%v\n", s2, len(s2), cap(s2))
}
```

输出：

```bash
s:[2 3] len(s):2 cap(s):4
s2:[5] len(s2):1 cap(s2):1
```

### 10.5.2 完整切片表达式

对于数组，指向数组的指针，或切片 a(**注意不能是字符串**) 支持完整切片表达式：

```go
a[low : high : max]
```

上面的代码会构造与简单切片表达式`a[low: high]`相同类型、相同长度和元素的切片。另外，它会将得到的结果切片的容量设置为`max-low`。在完整切片表达式中只有第一个索引值（low）可以省略；它默认为0。

```go
func main() {
	a := [5]int{1, 2, 3, 4, 5}
	t := a[1:3:5]
	fmt.Printf("t:%v len(t):%v cap(t):%v\n", t, len(t), cap(t))
}
```

输出结果：

```bash
t:[2 3] len(t):2 cap(t):4
```

完整切片表达式需要满足的条件是`0 <= low <= high <= max <= cap(a)`，其他条件和简单切片表达式相同。

## 10.6 使用 make() 函数构造切片

我们上面都是基于数组来创建的切片，如果需要动态的创建一个切片，我们就需要使用内置的`make()`函数，格式如下：

```bash
make([]T, size, cap)
```

其中：

- T:切片的元素类型
- size:切片中元素的数量
- cap:切片的容量

举个例子：

```go
func main() {
	a := make([]int, 2, 10)
	fmt.Println(a)      //[0 0]
	fmt.Println(len(a)) //2
	fmt.Println(cap(a)) //10
}
```

上面代码中`a`的内部存储空间已经分配了10个，但实际上只用了2个。 容量并不会影响当前元素的个数，所以`len(a)`返回2，`cap(a)`则返回该切片的容量。

## 10.7 切片的本质

切片的本质就是对底层数组的封装，它包含了三个信息：底层数组的指针、切片的长度（len）和切片的容量（cap）。

举个例子，现在有一个数组`a := [8]int{0, 1, 2, 3, 4, 5, 6, 7}`，切片`s1 := a[:5]`，相应示意图如下。

![image-20210411220113860](golang基础知识.assets/image-20210411220113860.png)

切片`s2 := a[3:6]`，相应示意图如下：

![image-20210411220130588](golang基础知识.assets/image-20210411220130588.png)

## 10.8 判断切片是否为空

要检查切片是否为空，请始终使用`len(s) == 0`来判断，而不应该使用`s == nil`来判断。

## 10.9 切片不能直接比较

切片之间是不能比较的，我们不能使用`==`操作符来判断两个切片是否含有全部相等元素。 切片唯一合法的比较操作是和`nil`比较。 一个`nil`值的切片并没有底层数组，一个`nil`值的切片的长度和容量都是0。但是我们不能说一个长度和容量都是0的切片一定是`nil`，例如下面的示例：

```go
var s1 []int         //len(s1)=0;cap(s1)=0;s1==nil
s2 := []int{}        //len(s2)=0;cap(s2)=0;s2!=nil
s3 := make([]int, 0) //len(s3)=0;cap(s3)=0;s3!=nil
```

所以要判断一个切片是否是空的，要是用`len(s) == 0`来判断，不应该使用`s == nil`来判断。

## 10.10  切片的赋值拷贝

下面的代码中演示了拷贝前后两个变量共享底层数组，对一个切片的修改会影响另一个切片的内容，这点需要特别注意。

```go
func main() {
	s1 := make([]int, 3) //[0 0 0]
	s2 := s1             //将s1直接赋值给s2，s1和s2共用一个底层数组
	s2[0] = 100
	fmt.Println(s1) //[100 0 0]
	fmt.Println(s2) //[100 0 0]
}
```

## 10.11 切片的遍历

切片的遍历方式和数组是一致的，支持索引遍历和`for range`遍历。

## 10.12 为切片添加元素：append()方法

1. Go语言的内建函数`append()`可以为切片动态添加元素。 可以一次添加一个元素，可以添加多个元素，也可以添加另一个切片中的元素（后面加…）。

    ```go
    func main(){
    	var s []int
    	s = append(s, 1)        // [1]
    	s = append(s, 2, 3, 4)  // [1 2 3 4]
    	s2 := []int{5, 6, 7}  
    	s = append(s, s2...)    // [1 2 3 4 5 6 7]
    }
    ```

    

2. **通过var声明的零值切片可以在`append()`函数直接使用，无需初始化。**

    ```go
    var s []int
    s = append(s, 1, 2, 3)
    ```

    没有必要像下面的代码一样初始化一个切片再传入`append()`函数使用，

    ```go
    s := []int{}  // 没有必要初始化
    s = append(s, 1, 2, 3)
    
    var s = make([]int)  // 没有必要初始化
    s = append(s, 1, 2, 3)
    ```

3. 每个切片会指向一个底层数组，这个数组的容量够用就添加新增元素。当底层数组不能容纳新增的元素时，切片就会自动按照一定的策略进行“扩容”，此时该切片指向的底层数组就会更换。“扩容”操作往往发生在`append()`函数调用时，所以我们通常都需要用原变量接收append函数的返回值。
    - `append()`函数将元素追加到切片的最后并返回该切片。
    - 切片 numSlice 的容量按照 1，2，4，8，16 这样的规则自动进行扩容，每次扩容后都是扩容前的 2 倍。

## 10.13 切片的扩容策略

可以通过查看`$GOROOT/src/runtime/slice.go`源码，其中扩容相关代码如下：

```go
newcap := old.cap
doublecap := newcap + newcap
if cap > doublecap {
	newcap = cap
} else {
	if old.len < 1024 {
		newcap = doublecap
	} else {
		// Check 0 < newcap to detect overflow
		// and prevent an infinite loop.
		for 0 < newcap && newcap < cap {
			newcap += newcap / 4
		}
		// Set newcap to the requested cap when
		// the newcap calculation overflowed.
		if newcap <= 0 {
			newcap = cap
		}
	}
}
```

从上面的代码可以看出以下内容：

- 首先判断，如果新申请容量（cap）大于2倍的旧容量（old.cap），最终容量（newcap）就是新申请的容量（cap）。
- 否则判断，如果旧切片的长度小于1024，则最终容量(newcap)就是旧容量(old.cap)的两倍，即（newcap=doublecap），
- 否则判断，如果旧切片长度大于等于1024，则最终容量（newcap）从旧容量（old.cap）开始循环增加原来的1/4，即（newcap=old.cap,for {newcap += newcap/4}）直到最终容量（newcap）大于等于新申请的容量(cap)，即（newcap >= cap）
- 如果最终容量（cap）计算值溢出，则最终容量（cap）就是新申请容量（cap）。

需要注意的是，切片扩容还会根据切片中元素的类型不同而做不同的处理，比如`int`和`string`类型的处理方式就不一样。 

## 10.14 使用 copy() 函数复制切片

首先我们来看一个问题：

```go
func main() {
	a := []int{1, 2, 3, 4, 5}
	b := a
	fmt.Println(a) //[1 2 3 4 5]
	fmt.Println(b) //[1 2 3 4 5]
	b[0] = 1000
	fmt.Println(a) //[1000 2 3 4 5]
	fmt.Println(b) //[1000 2 3 4 5]
}
```

由于切片是引用类型，所以 a 和 b 其实都指向了同一块内存地址。修改 b 的同时 a 的值也会发生变化。

Go语言内建的`copy()`函数可以迅速地将一个切片的数据复制到另外一个切片空间中，`copy()`函数的使用格式如下：

```bash
copy(destSlice, srcSlice []T)
```

其中：

- destSlice: 目标切片
- srcSlice: 数据来源切片

举个例子：

```go
func main() {
	// copy()复制切片
	a := []int{1, 2, 3, 4, 5}
	c := make([]int, 5, 5)
	copy(c, a)     //使用copy()函数将切片a中的元素复制到切片c
	fmt.Println(a) //[1 2 3 4 5]
	fmt.Println(c) //[1 2 3 4 5]
	c[0] = 1000
	fmt.Println(a) //[1 2 3 4 5]
	fmt.Println(c) //[1000 2 3 4 5]
}
```

## 10.15 从切片中删除元素

Go 语言中并没有删除切片元素的专用方法，我们可以使用切片本身的特性来删除元素。 代码如下：

```go
func main() {
	// 从切片中删除元素
	a := []int{30, 31, 32, 33, 34, 35, 36, 37}
	// 要删除索引为2的元素
	a = append(a[:2], a[3:]...)
	fmt.Println(a) //[30 31 33 34 35 36 37]
}
```

总结一下就是：要从切片 a 中删除索引为`index`的元素，操作方法是`a = append(a[:index], a[index+1:]...)`

# 11. map

> Go语言中提供的映射关系容器为`map`，其内部使用`散列表（hash）`实现。

## 11.1 map 定义

Go语言中 `map`的定义语法如下：

```go
map[KeyType]ValueType
```

其中，

- KeyType:表示键的类型。
- ValueType:表示键对应的值的类型。

map 类型的变量默认初始值为 nil，需要使用 make() 函数来分配内存。语法为：

```go
make(map[KeyType]ValueType, [cap])
```

**其中 cap 表示 map 的容量，该参数虽然不是必须的，但是我们应该在初始化 map 的时候就为其指定一个合适的容量。**

## 11.2 map 基本使用

map 中的数据都是成对出现的，map 的基本使用示例代码如下：

```go
func main() {
	scoreMap := make(map[string]int, 8)
	scoreMap["张三"] = 90
	scoreMap["小明"] = 100
	fmt.Println(scoreMap)
	fmt.Println(scoreMap["小明"])
	fmt.Printf("type of a:%T\n", scoreMap)
}
```

输出：

```bash
map[小明:100 张三:90]
100
type of a:map[string]int
```

map也支持在声明的时候填充元素，例如：

```go
func main() {
	userInfo := map[string]string{
		"username": "沙河小王子",
		"password": "123456",
	}
	fmt.Println(userInfo) //
}
```

## 11.3 判断某个键是否存在

Go语言中有个判断map中键是否存在的特殊写法，格式如下:

```go
value, ok := map[key]
```

举个例子：

```go
func main() {
	scoreMap := make(map[string]int)
	scoreMap["张三"] = 90
	scoreMap["小明"] = 100
	// 如果key存在ok为true,v为对应的值；不存在ok为false,v为值类型的零值
	v, ok := scoreMap["张三"]
	if ok {
		fmt.Println(v)
	} else {
		fmt.Println("查无此人")
	}
}
```

## 11.4 map的遍历

Go语言中使用`for range`遍历map。

```go
func main() {
	scoreMap := make(map[string]int)
	scoreMap["张三"] = 90
	scoreMap["小明"] = 100
	scoreMap["娜扎"] = 60
	for k, v := range scoreMap {
		fmt.Println(k, v)
	}
}
```

但我们只想遍历 key 的时候，可以按下面的写法：

```go
func main() {
	scoreMap := make(map[string]int)
	scoreMap["张三"] = 90
	scoreMap["小明"] = 100
	scoreMap["娜扎"] = 60
	for k := range scoreMap {
		fmt.Println(k)
	}
}
```

**注意：** 遍历map时的元素顺序与添加键值对的顺序无关。

## 11.5 使用delete()函数删除键值对

使用`delete()`内建函数从map中删除一组键值对，`delete()`函数的格式如下：

```go
delete(map, key)
```

其中，

- map:表示要删除键值对的map
- key:表示要删除的键值对的键

示例代码如下：

```go
func main(){
	scoreMap := make(map[string]int)
	scoreMap["张三"] = 90
	scoreMap["小明"] = 100
	scoreMap["娜扎"] = 60
	delete(scoreMap, "小明")//将小明:100从map中删除
	for k,v := range scoreMap{
		fmt.Println(k, v)
	}
}
```

## 11.6 按照指定顺序遍历 map

```go
func main() {
	rand.Seed(time.Now().UnixNano()) //初始化随机数种子

	var scoreMap = make(map[string]int, 200)

	for i := 0; i < 100; i++ {
		key := fmt.Sprintf("stu%02d", i) //生成stu开头的字符串
		value := rand.Intn(100)          //生成0~99的随机整数
		scoreMap[key] = value
	}
	//取出map中的所有key存入切片keys
	var keys = make([]string, 0, 200)
	for key := range scoreMap {
		keys = append(keys, key)
	}
	//对切片进行排序
	sort.Strings(keys)
	//按照排序后的key遍历map
	for _, key := range keys {
		fmt.Println(key, scoreMap[key])
	}
}
```

## 11.7 元素为 map 类型的切片

下面的代码演示了切片中的元素为 map 类型时的操作：

```go
func main() {
	var mapSlice = make([]map[string]string, 3)
	for index, value := range mapSlice {
		fmt.Printf("index:%d value:%v\n", index, value)
	}
	fmt.Println("after init")
	// 对切片中的map元素进行初始化
	mapSlice[0] = make(map[string]string, 10)
	mapSlice[0]["name"] = "小王子"
	mapSlice[0]["password"] = "123456"
	mapSlice[0]["address"] = "沙河"
	for index, value := range mapSlice {
		fmt.Printf("index:%d value:%v\n", index, value)
	}
}
```

## 11.8 值为切片类型的 map

下面的代码演示了 map 中值为切片类型的操作：

```go
func main() {
	var sliceMap = make(map[string][]string, 3)
	fmt.Println(sliceMap)
	fmt.Println("after init")
	key := "中国"
	value, ok := sliceMap[key]
	if !ok {
		value = make([]string, 0, 2)
	}
	value = append(value, "北京", "上海")
	sliceMap[key] = value
	fmt.Println(sliceMap)
}
```



# 12. 函数

> 函数是组织好的、可重复使用的、用于执行指定任务的代码块
> 
> Go 语言中支持函数、匿名函数和闭包，并且函数在 Go 语言中属于“一等公民”。

## 12.1 函数的定义

Go 语言中定义函数使用`func`关键字，具体格式如下：

```go
func 函数名(参数)(返回值){
    函数体
}
```

其中：

- 函数名：由字母、数字、下划线组成。但函数名的第一个字母不能是数字。在同一个包内，函数名也称不能重名（包的概念详见后文）。
- 参数：参数由参数变量和参数变量的类型组成，多个参数之间使用`,`分隔。
- 返回值：返回值由返回值变量和其变量类型组成，也可以只写返回值的类型，多个返回值必须用`()`包裹，并用`,`分隔。
- 函数体：实现指定功能的代码块。

我们先来定义一个求两个数之和的函数：

```go
func intSum(x int, y int) int {
	return x + y
}
```

函数的参数和返回值都是可选的，例如我们可以实现一个既不需要参数也没有返回值的函数：

```go
func sayHello() {
	fmt.Println("Hello 沙河")
}
```

## 12.2 函数的调用

定义了函数之后，我们可以通过 `函数名()` 的方式调用函数。

**注意，调用有返回值的函数时，可以不接收其返回值**

## 12.3 参数

### 12.3.1 类型简写

函数的参数中如果相邻变量的类型相同，则可以省略类型。例如

```go
func intSum(x, y int) int {
    return x + y
}
```

上面的代码中，intSum 函数有两个参数，这两个参数的类型均为 int，因此可以生V了



















































