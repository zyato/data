package main

import (
	"os"

	"yato/code/api/netease"
	"yato/code/api/tool"
)

func main() {
	file, err := os.OpenFile("./names.txt", os.O_RDONLY, 0666)
	if err != nil {
		panic(err)
	}
	defer file.Close()
	failFile, err := os.OpenFile("download_failed_music.txt", os.O_CREATE|os.O_RDWR|os.O_APPEND, 0666)
	if err != nil {
		panic(err)
	}
	existSongs, err := tool.LoadExistsSongs(tool.DownloadPath)
	if err != nil {
		panic(err)
	}
	defer failFile.Close()
	// kugou.Music(file, failFile, existSongs)
	// qq.Music(file, failFile, existSongs)
	netease.Music(file, failFile, existSongs)
}
