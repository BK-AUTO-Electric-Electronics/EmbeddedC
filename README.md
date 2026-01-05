# A. Cách chạy chương trình
## 1. Build and Run

```bash
    mingw32-make all
    main.exe 
    mingw32-make clean
```

## 2. Add module
`module_manager.h`
```c
   void add_module(const char *name, void (*on)(Module*), void (*off)(Module*), void (*check)(Module*));
```
## 3.Simulate error
`error_handler.h`
```c
    void fake_error(Module *m);
```
## 4. Check status
`function_handler.h`
```c
    void (name of module)_check(Module *m);
```
## 5. Turn ``on / off ``
`function_handler.h`
```c
    void engine_on(Module *m);
    void engine_off(Module *m);
```

## 6. List
`module_manager.h`
```c
    void list_modules(void);
```

## 7. Remove module
`module_manager.h`
```c
    void remove_module(int id);
```

## 8. Choose modules
`module_manager.h`
```c
    Module* get_module(int id);
```

# B. Flowchart

![alt text](image-1.png)