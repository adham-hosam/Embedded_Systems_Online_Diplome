.global start
start:
      ldr sp,=stack_top
	  bl main
stop: b stop
	