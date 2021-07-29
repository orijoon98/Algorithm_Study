import Foundation

let n = readLine()

var array = readLine()!.split(separator: " ").map {Int(String($0))!}

array.sort()

print(array[0], array[array.count-1])
