
SET(COMMON croutine.c  event_groups.c  list.c  queue.c  stream_buffer.c  tasks.c  timers.c)
SET(PORT   port.c)

IF(USE_FPU)
    SET(FOLDER Source/portable/GCC/stm32duino_m4)
ELSE(USE_FPU)
    SET(FOLDER Source/portable/GCC/stm32duino_m3)
ENDIF(USE_FPU)


SET(MEM  heap_4.c )
FOREACH(in ${COMMON})
    LIST(APPEND COMMON_EX Source/${in})
ENDFOREACH(in ${COMMON})
FOREACH(in ${MEM})
    LIST(APPEND MEM_EX Source/portable/MemMang/${in})
ENDFOREACH(in ${MEM})
FOREACH(in ${PORT})
    LIST(APPEND PORT_EX ${FOLDER}/${in})
ENDFOREACH(in ${PORT})

generate_arduino_library(${libPrefix}FreeRTOS 
                            SRCS ${COMMON_EX} ${PORT_EX} ${MEM_EX} MapleFreeRTOS1000_pp.cpp Source/portable/GCC/stm32duino/stm32duino.c
                            BOARD ${ARDUINO_DEFAULT_BOARD}
                        )

target_include_directories(${libPrefix}FreeRTOS  PRIVATE ${FOLDER})                        
