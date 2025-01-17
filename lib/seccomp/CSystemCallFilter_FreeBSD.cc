/*
 * Copyright Elasticsearch B.V. and/or licensed to Elasticsearch B.V. under one
 * or more contributor license agreements. Licensed under the Elastic License
 * 2.0 and the following additional limitation. Functionality enabled by the
 * files subject to the Elastic License 2.0 may only be used in production when
 * invoked by an Elasticsearch process with a license key installed that permits
 * use of machine learning features. You may not use this file except in
 * compliance with the Elastic License 2.0 and the foregoing additional
 * limitation.
 */
#include <seccomp/CSystemCallFilter.h>

#include <core/CLogger.h>

#include <paths.h>
#include <unistd.h>

#include <cerrno>
#include <cstring>

namespace ml {
namespace seccomp {

namespace {
std::string getTempDir() {
    // Prefer to use the temporary directory set by the Elasticsearch JVM
    const char* tmpDir{::getenv("TMPDIR")};

    // If TMPDIR is not set use _PATH_VARTMP
    std::string path{(tmpDir == nullptr) ? _PATH_VARTMP : tmpDir};
    // Make sure path ends with a slash so it's ready to have a file name appended
    if (path[path.length() - 1] != '/') {
        path += '/';
    }
    return path;
}
}

void CSystemCallFilter::installSystemCallFilter() {
    // todo
}

}
}
