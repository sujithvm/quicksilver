import java.io.InputStream

class FastReader(in: InputStream) {

  var pos: Int = 0
  var count: Int = 0
  var buf: Array[Byte] = new Array[Byte](1 << 16)

  private def read(): Byte = {
    if (pos == count) {
      try {
        pos = 0
        count = in.read(buf, pos, buf.length)
        if (count == -1) {
          buf(0) = -1
        }
      } catch {
        case e: Exception => ;
      }
    }
    var b: Byte = buf(pos)
    pos += 1
    return b
  }

  def readLong(): Long = {
    var c: Byte = read
    var sign: Byte = 1
    while (c <= ' ') {
      c = read
    }
    if (c == '-') {
      sign = -1
      c = read
    }
    var n: Long = 0L
    do {
      n = n * 10 + c - '0'
      c = read
    } while (c >= '0' && c <= '9')
    return n * sign
  }

  def readInt(): Int = {
    return readLong.toInt
  }

  def readDouble(): Double = {
    return readString.toDouble
  }

  def readChar(): Char = {
    var c: Byte = read
    while (c <= ' ')
      c = read
    return c.toChar
  }

  def readString(): String = {
    var sb: StringBuilder = new StringBuilder()
    var c: Byte = read
    while (c <= ' ')
      c = read
    while (c > ' ') {
      sb.append(c.toChar)
      c = read
    }
    return sb.toString
  }

  def readLine(): String = {
    var sb: StringBuilder = new StringBuilder()
    var c: Byte = read
    while (c < ' ')
      c = read
    while (c > ' ') {
      sb.append(c.toChar)
      c = read
    }
    return sb.toString
  }

  def readIntArray(size: Int): Array[Int] = {
    var arr: Array[Int] = new Array[Int](size)
    for (i <- 0 until size) {
      arr(i) = readInt
    }
    return arr
  }

  def readLongArray(size: Int): Array[Long] = {
    var arr: Array[Long] = new Array[Long](size)
    for (i <- 0 until size) {
      arr(i) = readLong
    }
    return arr
  }

  def readDoubleArray(size: Int): Array[Double] = {
    var arr: Array[Double] = new Array[Double](size)
    for (i <- 0 until size) {
      arr(i) = readDouble
    }
    return arr
  }

  def readStringArray(size: Int): Array[String] = {
    var arr: Array[String] = new Array[String](size)
    for (i <- 0 until size) {
      arr(i) = readString
    }
    return arr
  }
}
