package main

import (
	"bufio"
	"os"
	"strconv"
)

var sc = newScanner()

type scanner struct {
	*bufio.Scanner
}

func newScanner() *scanner {
	sc := &scanner{
		Scanner: bufio.NewScanner(os.Stdin),
	}
	sc.Split(bufio.ScanWords)
	return sc
}

func (sc *scanner) gInt() int {
	sc.Scan()
	v, _ := strconv.Atoi(sc.Text())
	return v
}
