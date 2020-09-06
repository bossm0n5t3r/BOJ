private var result = 64
private var N = 0
private var M = 0
private val cctvList: MutableList<Cctv> = mutableListOf<Cctv>()
private lateinit var map: Array<IntArray>

data class Cctv(
    val type: Int,
    val r: Int,
    val c: Int
)

fun main() {
    val input = readLine()!!.split(" ").map { it.toInt() }
    N = input[0]
    M = input[1]
    map = Array(N) { IntArray(M) }
    for (r in 0..(N - 1)) {
        val row: IntArray = readLine()!!.split(" ").map { it.toInt() }.toIntArray()
        map[r] = row
        for (c in 0..(M - 1)) {
            val type = map[r][c]
            if (type in 1..5) {
                val cctv = Cctv(
                    type = type,
                    r = r,
                    c = c
                )
                cctvList.add(cctv)
            }
        }
    }
    search(0, map)
    println(result)
}

private fun search(cctvIndex: Int, prev: Array<IntArray>) {
    if (cctvIndex == cctvList.size) {
        var tmp = 0
        for (r in 0..(N - 1)) {
            for (c in 0..(M - 1)) {
                if (prev[r][c] == 0) tmp++
            }
        }
        if (tmp < result) result = tmp
    } else {
        val cur = cctvList[cctvIndex]
        val type = cur.type
        val r = cur.r
        val c = cur.c
        when (type) {
            1 -> {
                for (k in 0..3) {
                    val visited = prev.copy()
                    detect(visited, r, c, k)
                    search(cctvIndex + 1, visited)
                }
            }
            2 -> {
                for (k in 0..1) {
                    val visited = prev.copy()
                    detect(visited, r, c, k)
                    detect(visited, r, c, k + 2)
                    search(cctvIndex + 1, visited)
                }
            }
            3 -> {
                for (k in 0..3) {
                    val visited = prev.copy()
                    detect(visited, r, c, k)
                    detect(visited, r, c, k + 1)
                    search(cctvIndex + 1, visited)
                }
            }
            4 -> {
                for (k in 0..3) {
                    val visited = prev.copy()
                    detect(visited, r, c, k)
                    detect(visited, r, c, k + 1)
                    detect(visited, r, c, k + 2)
                    search(cctvIndex + 1, visited)
                }
            }
            5 -> {
                val visited = prev.copy()
                detect(visited, r, c, 0)
                detect(visited, r, c, 1)
                detect(visited, r, c, 2)
                detect(visited, r, c, 3)
                search(cctvIndex + 1, visited)
            }
            else -> {}
        }
    }
}

private fun Array<IntArray>.copy() = Array(N) { get(it).copyOf() }

private fun detect(visited: Array<IntArray>, r: Int, c: Int, direction: Int) {
    var dir = direction % 4
    when (dir) {
        0 -> {
            for (newC in c downTo 0 step 1) {
                if (map[r][newC] == 6) break
                visited[r][newC] = 7
            }
        }
        1 -> {
            for (newR in r downTo 0 step 1) {
                if (map[newR][c] == 6) break
                visited[newR][c] = 7
            }
        }
        2 -> {
            for (newC in c until M) {
                if (map[r][newC] == 6) break
                visited[r][newC] = 7
            }
        }
        3 -> {
            for (newR in r until N) {
                if (map[newR][c] == 6) break
                visited[newR][c] = 7
            }
        }
        else -> {}
    }
}
