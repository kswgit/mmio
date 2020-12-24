import angr

h = []

def f(a):
    global h
    print(a)
    h = a

proj = angr.Project("pc9in.elf" , auto_load_libs=False)
proj.hook(0x8010, f, length=8 * 2)

state = proj.factory.call_state(0x800c)
#state = proj.factory.entry_state()
simgr = proj.factory.simgr(state)
cfg = proj.analyses.CFGEmulated(keep_state=True)
#cfg = proj.analyses.CFGFast()

print(cfg)
av = [0x815c]

simgr.use_technique(angr.exploration_techniques.LoopSeer(cfg=cfg, bound=2))
simgr.explore(avoid=av)
