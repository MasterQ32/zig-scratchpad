const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const mod_c = b.createModule(.{});
    mod_c.addCSourceFile(.{
        .file = .{ .path = "vendor/lib-c/lib-c.c" },
        .flags = &.{},
    });
    mod_c.link_libc = true;
    mod_c.addIncludePath(.{ .path = "vendor/lib-c/include" });

    const mod_b = b.createModule(.{});
    mod_b.addCSourceFile(.{
        .file = .{ .path = "vendor/lib-b/lib-b.c" },
        .flags = &.{},
    });
    mod_b.link_libc = true;
    mod_b.addImport("mod-c", mod_c);
    mod_b.addIncludePath(.{ .path = "vendor/lib-b/include" });

    const mod_a = b.createModule(.{});
    mod_a.addCSourceFile(.{
        .file = .{ .path = "vendor/lib-a/lib-a.c" },
        .flags = &.{},
    });
    mod_a.link_libc = true;
    mod_a.addIncludePath(.{ .path = "vendor/lib-a/include" });

    const exe = b.addExecutable(.{
        .name = "demo",
        .target = target,
        .optimize = optimize,
    });

    exe.linkLibC();
    exe.root_module.addCSourceFile(.{
        .file = .{ .path = "src/exe.c" },
        .flags = &.{},
    });

    exe.root_module.addImport("mod-a", mod_a);
    exe.root_module.addImport("mod-b", mod_b);

    b.installArtifact(exe);
}
