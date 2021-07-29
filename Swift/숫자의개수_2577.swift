import Foundation

var array = [Int](repeating: 0, count: 10)

var num : Int = 1

for _ in 1...3 {
    let n = Int(readLine()!)!
    num *= n
}

for i in 0..<String(num).count {
    array[Int(String(num)[String(num).index(String(num).startIndex, offsetBy: i)].asciiValue!) - 48] += 1
}

for i in 0...9 {
    print(array[i])
}
