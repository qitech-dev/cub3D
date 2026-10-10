# cub3D mandatory 测试集

本目录只覆盖 Version 12.0 的 mandatory：场景解析、四面墙纹理、地板与天花板颜色、WASD、方向键、ESC、关闭按钮和窗口操作。

不要求实现墙体碰撞、minimap、门、动画精灵或鼠标旋转。即使没有碰撞，按键操作后程序仍应保持稳定。

已有的 `maps/test.cub`、`maps/valid/test_color.cub`、项目源码和根目录 README 均未修改。本测试集使用自己在 `assets/` 中提供的纹理，与根目录 `textures/` 无关。

## 目录与预期结果

| 路径 | 数量 | 预期 |
| --- | ---: | --- |
| `valid/` | 34 | 解析成功，加载纹理后显示窗口 |
| `invalid/config/` | 22 | 配置缺失、重复、非法标识符或顺序错误，应报错退出 |
| `invalid/color/` | 30 | RGB 范围、数量或格式错误，应报错退出 |
| `invalid/player/` | 7 | 无玩家、多玩家或玩家在开放边界，应报错退出 |
| `invalid/map/` | 23 | 开放地图、空格邻接、非法字符、地图中断等，应报错退出 |
| `invalid/file/` | 9 | 空文件、错误扩展名、目录路径或不存在的文件，应报错退出 |
| `invalid/texture/` | 11 | 路径缺失或文件内容无效，应报错退出 |

共有 **136 个测试条目**：34 个有效场景、99 个解析拒绝用例、3 个纹理加载失败用例。

`cases.json` 保存每个用例的目的和预期。`CASE_INDEX.md` 是可阅读的完整清单。

三个状态的含义：

- `accept`：有效场景。检查地图尺寸、出生位置及方向、RGB、四个纹理路径和地图行内容。
- `reject`：应在解析阶段返回失败，并向 stderr 输出 `Error\n` 和非空说明。崩溃或超时不算通过。
- `load_error`：路径可以打开，但内容不是有效纹理。当前解析器只检查可打开性，因此解析检查应通过，实际启动应在纹理加载阶段报错。以后若将图片内容校验提前，需同步调整检查阶段。

`invalid/file/does_not_exist.cub` **故意不存在**，它仍是一个测试条目。`invalid/file/directory.cub` 和 `assets/directory.xpm` **故意是目录**。不要为这些路径补建普通文件。

## 无窗口批量解析检查

在项目根目录运行：

```bash
python3 maps/mandatory/run_parser_tests.py
```

依赖：Python 3、`cc` 和 `ar`。可通过 `CC` 环境变量指定编译器；临时链接使用 Linux 的 `--gc-sections`。

脚本在 `/tmp` 的临时目录中重新编译当前解析源码与 libft，使用项目本来的 `init_config()`、`parse_file()` 和 `free_config()`。每个用例都在独立进程中运行，避免 `get_next_line()` 静态缓存污染后续结果。

成功解析后，不仅检查退出码，还检查地图尺寸、出生位置、方向、颜色、路径以及地图每一行的内容哈希。前导、尾随空格被删掉也会失败。测试预期来自用例定义，不随当前解析器的结果自动改变。

项目目录不会产生新的编译文件。临时文件会在结束后清理；脚本退出码为：

- `0`：所有选定的解析预期符合。
- `1`：至少一个用例结果不符合预期。
- `2`：参数、编译或运行环境错误。

查看清单或只检查某一类：

```bash
python3 maps/mandatory/run_parser_tests.py --list
python3 maps/mandatory/run_parser_tests.py --case valid/
python3 maps/mandatory/run_parser_tests.py --case invalid/color/
python3 maps/mandatory/run_parser_tests.py --case nul_
```

**解析通过不等于 mandatory 全部通过。** 脚本不检查图像加载、渲染、窗口事件、泄漏、Norm、README 或 Makefile 行为。

## 实际运行场景

以下命令均从项目根目录运行；场景内的纹理路径以进程工作目录为基准。

先用项目自己的 Makefile 编译，再运行场景：

```bash
make
./cub3D maps/mandatory/valid/room.cub
./cub3D maps/mandatory/valid/four_wall_faces.cub
./cub3D maps/mandatory/valid/different_texture_sizes.cub
```

逐张检查全部有效场景，每次正常退出后打开下一张：

```bash
for scene in maps/mandatory/valid/*.cub; do
    ./cub3D "$scene" || break
done
```

纹理加载失败需要单独检查，确保错误来自无效图片，而不是没有可用显示环境：

```bash
./cub3D maps/mandatory/invalid/texture/not_an_xpm.cub
./cub3D maps/mandatory/invalid/texture/empty_xpm.cub
./cub3D maps/mandatory/invalid/texture/directory_texture.cub
```

这些场景应输出 `Error` 和明确说明，并正常返回非零退出码。解析脚本无法替代这三项图形初始化检查。

## 墙面与纹理检查

基础纹理是 8×8 的 XPM，带字母和左上角白色标记，便于识别方向和观察取样：

| 配置 | 主色 | 字母 |
| --- | --- | --- |
| `NO` | 红色 | N |
| `SO` | 绿色 | S |
| `WE` | 蓝色 | W |
| `EA` | 黄色 | E |

纹理标识表示**墙面的朝向**，不是玩家看的方向。在房间内看外围墙，或从中央墙柱的相应一侧观察时：

| 视线方向 | 看到的墙面 | 预期纹理 |
| --- | --- | --- |
| 向北 | 墙的南面 | `SO`，绿色 |
| 向南 | 墙的北面 | `NO`，红色 |
| 向东 | 墙的西面 | `WE`，蓝色 |
| 向西 | 墙的东面 | `EA`，黄色 |

用 `four_wall_faces.cub` 绕墙柱观察四面。检查墙角处有没有明显跳变、错误面或纹理越界。

`different_texture_sizes.cub` 混合使用 17×5、5×17、1×1 和 8×8 纹理，检查代码有没有把纹理宽高固定成 `BLOCK` 或假定纹理必须是正方形。`texture_path_spaces.cub` 使用带空格的文件名；`texture_extension.cub` 使用 XPM 内容但不同扩展名。

## mandatory 手动检查

使用 `room.cub`、`maze.cub` 和两张走廊地图逐项检查：

1. W/S 前进后退，A/D 左右平移；左右箭头旋转。按下、持续按住、松开后行为正确。
2. 转动过程中，墙、天空和地板保持正常；能区分四个墙面方向。
3. 黑地板、白天花板以及 RGB 边界场景颜色正确；颜色零值不会被误认为缺失配置。
4. ESC 正常退出；重新启动后，点击窗口关闭按钮正常退出。
5. 切换到其他窗口、最小化、恢复、遮挡再显示，窗口保持可用；恢复后没有卡住的按键状态。
6. 同时按移动和旋转键，程序保持响应。
7. 靠近墙、进入墙或移动到地图外时，程序不崩溃、不产生非法计算。**此项检查稳定性，不要求墙体碰撞 Bonus。**
8. 在错误场景、正常 ESC 和关闭按钮路径上分别检查内存。解析脚本没有宣称检查过泄漏。

若环境有 Valgrind，可以从根目录运行：

```bash
valgrind --leak-check=full --show-leak-kinds=all ./cub3D maps/mandatory/valid/room.cub
valgrind --leak-check=full --show-leak-kinds=all ./cub3D maps/mandatory/invalid/config/duplicate_no.cub
```

图形程序内存报告应区分项目自己的资源和第三方库分配，不能仅凭解析返回值判定没有泄漏。

## 参数、权限和构建检查

以下错误必须输出 `Error\n` 和说明，并正常退出：

```bash
./cub3D
./cub3D maps/mandatory/valid/room.cub extra_argument
./cub3D maps/mandatory/invalid/file/does_not_exist.cub
./cub3D maps/mandatory/invalid/file/directory.cub
./cub3D maps/mandatory/invalid/file/wrong_extension.txt
```

没有读取权限的地图或纹理也应正常报错。权限在 Git 中不能可靠保存，且特权用户可能仍能读取，所以没有提供依赖 `chmod 000` 的固定用例；可在临时文件上另行测试。

另外检查 `make` 首次构建成功、再次运行没有无意义重新链接，`clean/fclean/re` 正常工作，并单独检查 Norm 和题目规定的英文根目录 README。这些都无法由 `.cub` 文件本身验证。

## 本次检查发现的失败用例

新增时对当前源码运行解析脚本，结果为 **134/136 项符合预期**。

以下两份非法场景被错误地接受：

- `invalid/map/nul_after_wall.cub`：最后一行墙之后有 NUL 字节及非法字符。
- `invalid/map/nul_hides_trailing_text.cub`：NUL 字节后有地图格式不允许的文本。

NUL 是字节 `0x00`，不是地图允许的字符。普通编辑器可能不显示它；可用下面的命令查看实际字节：

```bash
od -An -tx1c maps/mandatory/invalid/map/nul_after_wall.cub
```

当前逐行读取中的字符串操作会把 NUL 当作字符串结束，部分输入因而被截断或忽略。两份用例保留“应拒绝”的预期，项目源码未修改。

另外三份 `load_error` 场景只验证了当前解析阶段接受它们；本次没有验证实际图片加载、窗口操作或内存泄漏。
