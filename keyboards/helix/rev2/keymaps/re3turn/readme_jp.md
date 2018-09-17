# The Helix Layout

## 配列

### Qwerty配列

```text
 ,-----------------------------------------.             ,-----------------------------------------.
 |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |  -   |
 |------+------+------+------+------+------|             |------+------+------+------+------+------|
 | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |  =   |
 |------+------+------+------+------+------|             |------+------+------+------+------+------|
 | Alt  |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
 |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 | Shift|   Z  |   X  |   C  |   V  |   B  |   [  |   ]  |   N  |   M  |   ,  |   .  |   /  |  -   |
 |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 | Ctrl | GUI  | Alt  | KANA | Esc/ |Space/| Tab/ | BS   |Enter/| Del  | GUI+ | Alt  | GUI/ |  \   |
 |      |      |      |      | Ctrl |~Lower| Shift|      |~Raise|      | Tab  |      |~Adjst|      |
 `-------------------------------------------------------------------------------------------------'
```

他の配列(Colemak,Eucalyn)は、[readme.md](readme.md) を参照

## コンパイルの仕方

コンパイルは、qmk_firmware のトップディレクトリで行います。

```bash
cd qmk_firmware
```

qmk_firmwareでは各キーボードのコンパイルは、`<キーボード名>:<キーマップ名>`という指定で行います。

```bash
make helix:re3turn
```

キーボードへの書き込みまで同時に行うには下記のように`:avrdude`を付けます。

```bash
make helix:re3turn:avrdude
```

コンパイル結果と中間生成物を消去したい場合は以下のようにします。

```bash
make helix:re3turn:clean
```

## カスタマイズ

Helix キーボードを4行版として製作したり、オプションの OLED をつけたり、
RGB バックライトまたは、RGB Underglow をつけた場合は、
`qmk_firmware/keyboards/helix/rev2/keymaps/re3turn/rules.mk` の以下の部分を編集して機能を有効化してください。

```text
# Helix keyboard customize
# you can edit follows 7 Variables
#  jp: 以下の7つの変数を必要に応じて編集します。
HELIX_ROWS = 5              # Helix Rows is 4 or 5
OLED_ENABLE = no            # OLED_ENABLE
LOCAL_GLCDFONT = no         # use each keymaps "helixfont.h" insted of "common/glcdfont.c"
LED_BACK_ENABLE = no        # LED backlight (Enable WS2812 RGB underlight.)
LED_UNDERGLOW_ENABLE = yes  # LED underglow (Enable WS2812 RGB underlight.)
LED_ANIMATIONS = no         # LED animations
IOS_DEVICE_ENABLE = no      # connect to IOS device (iPad,iPhone)
```

## 4行版Helix に対応する

rules.mk の下記の部分を編集して 5 を 4 に変更してください。

```:text
HELIX_ROWS = 4              # Helix Rows is 4 or 5
```

## RGB バックライトを有効にする

rules.mk の下記の部分を編集して no を yes に変更してください。

```text
LED_BACK_ENABLE = yes        # LED backlight (Enable WS2812 RGB underlight.)
```

## RGB Underglow を有効にする

rules.mk の下記の部分を編集して no を yes に変更してください。

```text
LED_UNDERGLOW_ENABLE = yes   # LED underglow (Enable WS2812 RGB underlight.)
```

## OLEDを有効にする

rules.mk の下記の部分を編集して no を yes に変更してください。

```text
OLED_ENABLE = yes            # OLED_ENABLE
```

## iPad/iPhoneサポートを有効にする。

rules.mk の下記の部分を編集して no を yes に変更してください。
RBG Underglow や RGBバックライトの輝度を抑えて、iPad, iPhone にも接続できるようになります。

```text
IOS_DEVICE_ENABLE = no      # connect to IOS device (iPad,iPhone)
```

## リンク

* さらに詳細は、[こちら helix/Doc/firmware_jp.md](https://github.com/MakotoKurauchi/helix/blob/master/Doc/firmware_jp.md)をご覧ください。
* [Helix top](https://github.com/MakotoKurauchi/helix)
