# Mandatory 用例清单

从项目根目录运行，路径前加 `maps/mandatory/`。

`accept` 应正常显示窗口；`reject` 应在解析时输出 Error 并退出；`load_error` 应在图片加载时输出 Error 并退出。

完整判定信息见 `cases.json`；批量脚本只检查解析。

| 用例 | 预期 | 检查目的 |
| --- | --- | --- |
| `valid/spawn_n.cub` | `accept` | 出生方向 N |
| `valid/spawn_s.cub` | `accept` | 出生方向 S |
| `valid/spawn_e.cub` | `accept` | 出生方向 E |
| `valid/spawn_w.cub` | `accept` | 出生方向 W |
| `valid/minimal_3x3.cub` | `accept` | 最小封闭地图；玩家紧邻四面墙 |
| `valid/room.cub` | `accept` | 开放房间；检查视角、地板和天花板 |
| `valid/horizontal_corridor.cub` | `accept` | 一格宽的水平走廊 |
| `valid/vertical_corridor.cub` | `accept` | 一格宽的垂直走廊 |
| `valid/maze.cub` | `accept` | 带拐角、通道和内部墙的迷宫 |
| `valid/four_wall_faces.cub` | `accept` | 绕中央墙柱观察四个方向的纹理；检查墙角取样 |
| `valid/ragged_closed.cub` | `accept` | 不等长行仍封闭；不能按最长行直接访问每一行 |
| `valid/leading_map_spaces.cub` | `accept` | 地图每行保留三个前导空格 |
| `valid/trailing_map_spaces.cub` | `accept` | 地图每行保留数量不同的尾随空格 |
| `valid/enclosed_void.cub` | `accept` | 空格空洞被墙包围，不邻接可行走区域 |
| `valid/separate_closed_rooms.cub` | `accept` | 两个封闭区域用空格隔开；全图只有一个玩家 |
| `valid/wall_only_row.cub` | `accept` | 整行墙分隔封闭区域 |
| `valid/config_order_reverse.cub` | `accept` | 配置顺序：reverse |
| `valid/config_order_mixed.cub` | `accept` | 配置顺序：mixed |
| `valid/config_order_colors_first.cub` | `accept` | 配置顺序：colors_first |
| `valid/config_blank_lines.cub` | `accept` | 配置之间允许多个空行和空白行 |
| `valid/config_whitespace.cub` | `accept` | 配置前后及标识符后有空格和制表符 |
| `valid/rgb_boundaries.cub` | `accept` | RGB 的 0 和 255 边界 |
| `valid/black_floor_white_ceiling.cub` | `accept` | 黑地板、白天花板，零值应视为已配置 |
| `valid/rgb_component_whitespace.cub` | `accept` | RGB 数字和逗号周围允许空格及制表符 |
| `valid/rgb_leading_zeroes.cub` | `accept` | RGB 十进制数字的前导零 |
| `valid/no_final_newline.cub` | `accept` | 文件最后没有换行符 |
| `valid/no_config_map_separator.cub` | `accept` | 配置与地图之间不要求空行 |
| `valid/leading_trailing_blank_lines.cub` | `accept` | 文件前后有多个空行，地图内部没有空行 |
| `valid/different_texture_sizes.cub` | `accept` | 17x5、5x17、1x1、8x8 纹理；纹理尺寸不依赖 BLOCK |
| `valid/texture_path_spaces.cub` | `accept` | 纹理文件名含空格 |
| `valid/texture_extension.cub` | `accept` | 有效 XPM 内容使用其他扩展名；题目只限定场景的 .cub 扩展名 |
| `valid/long_row_256.cub` | `accept` | 256 列地图，跨越多个 get_next_line 读取缓冲区 |
| `valid/tall_map_128.cub` | `accept` | 128 行地图，检查地图行数组扩展 |
| `valid/long_config_whitespace.cub` | `accept` | 配置前有 4096 个空格 |
| `invalid/config/missing_no.cub` | `reject` | 缺少 NO 配置 |
| `invalid/config/duplicate_no.cub` | `reject` | NO 重复配置 |
| `invalid/texture/empty_no_path.cub` | `reject` | NO 纹理路径为空 |
| `invalid/texture/missing_no_file.cub` | `reject` | NO 纹理文件不存在 |
| `invalid/config/missing_so.cub` | `reject` | 缺少 SO 配置 |
| `invalid/config/duplicate_so.cub` | `reject` | SO 重复配置 |
| `invalid/texture/empty_so_path.cub` | `reject` | SO 纹理路径为空 |
| `invalid/texture/missing_so_file.cub` | `reject` | SO 纹理文件不存在 |
| `invalid/config/missing_we.cub` | `reject` | 缺少 WE 配置 |
| `invalid/config/duplicate_we.cub` | `reject` | WE 重复配置 |
| `invalid/texture/empty_we_path.cub` | `reject` | WE 纹理路径为空 |
| `invalid/texture/missing_we_file.cub` | `reject` | WE 纹理文件不存在 |
| `invalid/config/missing_ea.cub` | `reject` | 缺少 EA 配置 |
| `invalid/config/duplicate_ea.cub` | `reject` | EA 重复配置 |
| `invalid/texture/empty_ea_path.cub` | `reject` | EA 纹理路径为空 |
| `invalid/texture/missing_ea_file.cub` | `reject` | EA 纹理文件不存在 |
| `invalid/config/missing_f.cub` | `reject` | 缺少 F 配置 |
| `invalid/config/duplicate_f.cub` | `reject` | F 重复配置 |
| `invalid/config/missing_c.cub` | `reject` | 缺少 C 配置 |
| `invalid/config/duplicate_c.cub` | `reject` | C 重复配置 |
| `invalid/config/unknown_identifier.cub` | `reject` | 未知配置标识符 |
| `invalid/config/lowercase_identifier.cub` | `reject` | 小写配置标识符 |
| `invalid/config/missing_identifier_separator.cub` | `reject` | 标识符与路径之间没有空白 |
| `invalid/config/comment_line.cub` | `reject` | 格式不支持注释行 |
| `invalid/config/extra_identifier.cub` | `reject` | 纹理标识符后有多余字符 |
| `invalid/config/identifier_only.cub` | `reject` | 文件仅含 NO 标识符，缺少路径 |
| `invalid/config/map_before_config.cub` | `reject` | 地图必须是文件的最后部分 |
| `invalid/config/texture_after_map.cub` | `reject` | 地图之后再次出现纹理配置 |
| `invalid/config/color_after_map.cub` | `reject` | 地图之后再次出现颜色配置 |
| `invalid/config/unknown_after_map.cub` | `reject` | 地图末尾出现非地图文本 |
| `invalid/color/f_red_negative.cub` | `reject` | F 的 red 分量为 -1 |
| `invalid/color/f_red_over_255.cub` | `reject` | F 的 red 分量为 256 |
| `invalid/color/f_green_negative.cub` | `reject` | F 的 green 分量为 -1 |
| `invalid/color/f_green_over_255.cub` | `reject` | F 的 green 分量为 256 |
| `invalid/color/f_blue_negative.cub` | `reject` | F 的 blue 分量为 -1 |
| `invalid/color/f_blue_over_255.cub` | `reject` | F 的 blue 分量为 256 |
| `invalid/color/f_empty.cub` | `reject` | F 缺少 RGB 数值 |
| `invalid/color/c_red_negative.cub` | `reject` | C 的 red 分量为 -1 |
| `invalid/color/c_red_over_255.cub` | `reject` | C 的 red 分量为 256 |
| `invalid/color/c_green_negative.cub` | `reject` | C 的 green 分量为 -1 |
| `invalid/color/c_green_over_255.cub` | `reject` | C 的 green 分量为 256 |
| `invalid/color/c_blue_negative.cub` | `reject` | C 的 blue 分量为 -1 |
| `invalid/color/c_blue_over_255.cub` | `reject` | C 的 blue 分量为 256 |
| `invalid/color/c_empty.cub` | `reject` | C 缺少 RGB 数值 |
| `invalid/color/one_component.cub` | `reject` | 只有一个 RGB 分量 |
| `invalid/color/two_components.cub` | `reject` | 只有两个 RGB 分量 |
| `invalid/color/four_components.cub` | `reject` | 多出第四个 RGB 分量 |
| `invalid/color/empty_red.cub` | `reject` | 红色分量为空 |
| `invalid/color/empty_green.cub` | `reject` | 绿色分量为空 |
| `invalid/color/empty_blue.cub` | `reject` | 蓝色分量为空 |
| `invalid/color/trailing_comma.cub` | `reject` | RGB 后多一个逗号 |
| `invalid/color/missing_commas.cub` | `reject` | RGB 没有逗号分隔 |
| `invalid/color/wrong_separator.cub` | `reject` | 使用分号分隔 RGB |
| `invalid/color/decimal_component.cub` | `reject` | RGB 分量不是整数 |
| `invalid/color/alphabetic_component.cub` | `reject` | RGB 分量含字母 |
| `invalid/color/hex_component.cub` | `reject` | RGB 分量使用非十进制形式 |
| `invalid/color/split_number.cub` | `reject` | 数字中间有空白 |
| `invalid/color/trailing_text.cub` | `reject` | RGB 后有多余文本 |
| `invalid/color/trailing_comment.cub` | `reject` | RGB 后有不支持的注释 |
| `invalid/color/very_large_number.cub` | `reject` | 超长且超出范围的数字应安全拒绝 |
| `invalid/player/missing_player.cub` | `reject` | 地图没有玩家 |
| `invalid/player/two_same_directions.cub` | `reject` | 地图出现两个 N 玩家 |
| `invalid/player/two_different_directions.cub` | `reject` | 地图出现 N 和 E 两个玩家 |
| `invalid/player/on_top_edge.cub` | `reject` | 玩家位于 top 开放边界 |
| `invalid/map/open_top.cub` | `reject` | 地图 top 边界有开放格子 |
| `invalid/player/on_bottom_edge.cub` | `reject` | 玩家位于 bottom 开放边界 |
| `invalid/map/open_bottom.cub` | `reject` | 地图 bottom 边界有开放格子 |
| `invalid/player/on_left_edge.cub` | `reject` | 玩家位于 left 开放边界 |
| `invalid/map/open_left.cub` | `reject` | 地图 left 边界有开放格子 |
| `invalid/player/on_right_edge.cub` | `reject` | 玩家位于 right 开放边界 |
| `invalid/map/open_right.cub` | `reject` | 地图 right 边界有开放格子 |
| `invalid/map/void_above_player.cub` | `reject` | 玩家的 above 邻居为空格 |
| `invalid/map/void_below_player.cub` | `reject` | 玩家的 below 邻居为空格 |
| `invalid/map/void_left_player.cub` | `reject` | 玩家的 left 邻居为空格 |
| `invalid/map/void_right_player.cub` | `reject` | 玩家的 right 邻居为空格 |
| `invalid/map/ragged_missing_above.cub` | `reject` | 短行导致可行走格子上方缺失 |
| `invalid/map/ragged_missing_below.cub` | `reject` | 短行导致可行走格子下方缺失 |
| `invalid/map/open_floor_to_void.cub` | `reject` | 空格邻接普通地板，即使不邻接玩家也必须拒绝 |
| `invalid/map/unsupported_digit.cub` | `reject` | 地图出现非法字符 2 |
| `invalid/map/unknown_character.cub` | `reject` | 地图出现非法字符 X |
| `invalid/map/lowercase_player.cub` | `reject` | 地图出现小写 n |
| `invalid/map/bonus_door_symbol.cub` | `reject` | mandatory 地图不允许门的额外符号 D |
| `invalid/map/blank_line_inside.cub` | `reject` | 地图中间出现空行 |
| `invalid/map/space_line_inside.cub` | `reject` | 地图中间出现仅含空格的行 |
| `invalid/map/two_maps.cub` | `reject` | 空行之后出现第二张地图 |
| `invalid/map/single_player_cell.cub` | `reject` | 单个玩家格子没有墙包围 |
| `invalid/map/no_walls.cub` | `reject` | 完全没有外围墙 |
| `invalid/map/wall_only.cub` | `reject` | 全是墙，没有玩家 |
| `invalid/map/nul_after_wall.cub` | `reject` | 最后一行含 NUL 和非法字符，不能当作合法文本截断 |
| `invalid/map/nul_hides_trailing_text.cub` | `reject` | NUL 不能隐藏地图之后的垃圾内容 |
| `invalid/file/empty.cub` | `reject` | 空文件 |
| `invalid/file/blank_only.cub` | `reject` | 文件只有空行和空白 |
| `invalid/file/config_only.cub` | `reject` | 只有完整配置，没有地图 |
| `invalid/file/wrong_extension.txt` | `reject` | 错误的 .txt 扩展名 |
| `invalid/file/uppercase_extension.CUB` | `reject` | 错误的 .CUB 扩展名 |
| `invalid/file/extra_extension.cub.bak` | `reject` | .cub 后还有其他扩展名 |
| `invalid/file/no_extension` | `reject` | 场景文件没有扩展名 |
| `invalid/file/directory.cub` | `reject` | .cub 路径实际为目录 |
| `invalid/file/does_not_exist.cub` | `reject` | 故意不创建此路径，检查无法打开的地图 |
| `invalid/texture/not_an_xpm.cub` | `load_error` | 路径可打开但不是有效纹理；应在图片加载阶段报 Error |
| `invalid/texture/empty_xpm.cub` | `load_error` | 路径可打开但不是有效纹理；应在图片加载阶段报 Error |
| `invalid/texture/directory_texture.cub` | `load_error` | 路径可打开但不是有效纹理；应在图片加载阶段报 Error |
