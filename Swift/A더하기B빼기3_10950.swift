import Foundation

var a = readLine()

let num = Int(a!)

for _ in 1...num! {
    let nums = readLine()
    let array = nums!.components(separatedBy: " ")
    let ans = Int(array[0])! + Int(array[1])!
    print(ans)
}

